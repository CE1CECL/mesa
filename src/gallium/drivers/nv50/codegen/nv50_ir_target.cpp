/*
 * Copyright 2011 Christoph Bumiller
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "nv50/codegen/nv50_ir.h"
#include "nv50/codegen/nv50_ir_target.h"

namespace nv50_ir {

const uint8_t Target::operationSrcNr[OP_LAST + 1] =
{
   0, 0,                   // NOP, PHI
   0, 0, 0, 0,             // UNION, SPLIT, MERGE, CONSTRAINT
   1, 1, 2,                // MOV, LOAD, STORE
   2, 2, 2, 2, 2, 3, 3, 3, // ADD, SUB, MUL, DIV, MOD, MAD, FMA, SAD
   1, 1, 1,                // ABS, NEG, NOT
   2, 2, 2, 2, 2,          // AND, OR, XOR, SHL, SHR
   2, 2, 1,                // MAX, MIN, SAT
   1, 1, 1, 1,             // CEIL, FLOOR, TRUNC, CVT
   3, 3, 3, 2, 3, 3,       // SET_AND,OR,XOR, SET, SELP, SLCT
   1, 1, 1, 1, 1, 1,       // RCP, RSQ, LG2, SIN, COS, EX2
   1, 1, 1, 1, 1, 2,       // EXP, LOG, PRESIN, PREEX2, SQRT, POW
   0, 0, 0, 0, 0,          // BRA, CALL, RET, CONT, BREAK,
   0, 0, 0,                // PRERET,CONT,BREAK
   0, 0, 0, 0, 0, 0,       // BRKPT, JOINAT, JOIN, DISCARD, EXIT, MEMBAR
   1, 1, 2, 1, 2,          // VFETCH, PFETCH, EXPORT, LINTERP, PINTERP
   1, 1,                   // EMIT, RESTART
   1, 1, 1,                // TEX, TXB, TXL,
   1, 1, 1, 1, 1,          // TXF, TXQ, TXD, TXG, TEXCSAA
   1, 2,                   // SULD, SUST
   1, 1,                   // DFDX, DFDY
   1, 2, 2, 2, 0, 0,       // RDSV, WRSV, PIXLD, QUADOP, QUADON, QUADPOP
   2, 3, 2,                // POPCNT, INSBF, EXTBF
   0
};


extern Target *getTargetNVC0(unsigned int chipset);

Target *Target::create(unsigned int chipset)
{
   switch (chipset & 0xf0) {
   case 0xc0:
      return getTargetNVC0(chipset);
   case 0x50:
   case 0x80:
   case 0x90:
   case 0xa0:
   default:
      ERROR("unsupported target: NV%x\n", chipset);
      return 0;
   }
}

void Target::destroy(Target *targ)
{
   delete targ;
}

void
CodeEmitter::setCodeLocation(void *ptr, uint32_t size)
{
   code = reinterpret_cast<uint32_t *>(ptr);
   codeSize = 0;
   codeSizeLimit = size;
}

void
CodeEmitter::printBinary() const
{
   uint32_t *bin = code - codeSize / 4;
   INFO("program binary (%u bytes)", codeSize);
   for (unsigned int pos = 0; pos < codeSize / 4; ++pos) {
      if ((pos % 8) == 0)
         INFO("\n");
      INFO("%08x ", bin[pos]);
   }
   INFO("\n");
}

void
CodeEmitter::prepareEmission(Program *prog)
{
   for (ArrayList::Iterator fi = prog->allFuncs.iterator();
        !fi.end(); fi.next()) {
      Function *func = reinterpret_cast<Function *>(fi.get());
      func->binPos = prog->binSize;
      prepareEmission(func);
      prog->binSize += func->binSize;
   }
}

void
CodeEmitter::prepareEmission(Function *func)
{
   func->bbCount = 0;
   func->bbArray = new BasicBlock * [func->cfg.getSize()];

   BasicBlock::get(func->cfg.getRoot())->binPos = func->binPos;

   Graph::GraphIterator *iter;
   for (iter = func->cfg.iteratorCFG(); !iter->end(); iter->next())
      prepareEmission(BasicBlock::get(*iter));
   func->cfg.putIterator(iter);
}

void
CodeEmitter::prepareEmission(BasicBlock *bb)
{
   Instruction *i, *next;
   Function *func = bb->getFunction();
   int j;
   unsigned int nShort;

   for (j = func->bbCount - 1; j >= 0 && !func->bbArray[j]->binSize; --j);

   for (; j >= 0; --j) {
      BasicBlock *in = func->bbArray[j];
      Instruction *exit = in->getExit();

      if (exit && exit->op == OP_BRA && exit->asFlow()->target.bb == bb) {
         in->binSize -= 8;
         func->binSize -= 8;

         for (++j; j < func->bbCount; ++j)
            func->bbArray[j]->binPos -= 8;

         in->remove(exit);
      }
      bb->binPos = in->binPos + in->binSize;
      if (in->binSize) // no more no-op branches to bb
         break;
   }
   func->bbArray[func->bbCount++] = bb;

   if (!bb->getExit())
      return;

   // determine encoding size, try to group short instructions
   nShort = 0;
   for (i = bb->getEntry(); i; i = next) {
      next = i->next;

      i->encSize = getMinEncodingSize(i);
      if (next && i->encSize < 8)
         ++nShort;
      else
      if ((nShort & 1) && next && getMinEncodingSize(next) == 4) {
         if (i->isCommutationLegal(i->next)) {
            bb->permuteAdjacent(i, next);
            next->encSize = 4;
            next = i;
            i = i->prev;
            ++nShort;
         } else
         if (i->isCommutationLegal(i->prev) && next->next) {
            bb->permuteAdjacent(i->prev, i);
            next->encSize = 4;
            next = next->next;
            bb->binSize += 4;
            ++nShort;
         } else {
            i->encSize = 8;
            i->prev->encSize = 8;
            bb->binSize += 4;
            nShort = 0;
         }
      } else {
         i->encSize = 8;
         if (nShort & 1) {
            i->prev->encSize = 8;
            bb->binSize += 4;
         }
         nShort = 0;
      }
      bb->binSize += i->encSize;
   }

   if (bb->getExit()->encSize == 4) {
      assert(nShort);
      bb->getExit()->encSize = 8;
      bb->binSize += 4;

      if ((bb->getExit()->prev->encSize == 4) && !(nShort & 1)) {
         bb->binSize += 8;
         bb->getExit()->prev->encSize = 8;
      }
   }
   assert(!bb->getEntry() || (bb->getExit() && bb->getExit()->encSize == 8));

   func->binSize += bb->binSize;
}

bool
Program::emitBinary(struct nv50_ir_prog_info *info)
{
   CodeEmitter *emit = target->getCodeEmitter(progType);

   emit->prepareEmission(this);

   if (dbgFlags & NV50_IR_DEBUG_BASIC)
      this->print();

   if (!binSize) {
      code = NULL;
      return false;
   }
   code = reinterpret_cast<uint32_t *>(MALLOC(binSize));
   if (!code)
      return false;
   emit->setCodeLocation(code, binSize);

   for (ArrayList::Iterator fi = allFuncs.iterator(); !fi.end(); fi.next()) {
      Function *fn = reinterpret_cast<Function *>(fi.get());

      assert(emit->getCodeSize() == fn->binPos);

      for (int b = 0; b < fn->bbCount; ++b)
         for (Instruction *i = fn->bbArray[b]->getEntry(); i; i = i->next)
            emit->emitInstruction(i);
   }
   info->bin.relocData = emit->getRelocInfo();

   delete emit;
   return true;
}

#define RELOC_ALLOC_INCREMENT 8

bool
CodeEmitter::addReloc(RelocEntry::Type ty, int w, uint32_t data, uint32_t m,
                      int s)
{
   unsigned int n = relocInfo ? relocInfo->count : 0;

   if (!(n % RELOC_ALLOC_INCREMENT)) {
      size_t size = sizeof(RelocInfo) + n * sizeof(RelocEntry);
      relocInfo = reinterpret_cast<RelocInfo *>(
         REALLOC(relocInfo, n ? size : 0,
                 size + RELOC_ALLOC_INCREMENT * sizeof(RelocEntry)));
      if (!relocInfo)
         return false;
   }
   ++relocInfo->count;

   relocInfo->entry[n].data = data;
   relocInfo->entry[n].mask = m;
   relocInfo->entry[n].offset = codeSize + w * 4;
   relocInfo->entry[n].bitPos = s;
   relocInfo->entry[n].type = ty;

   return true;
}

void
RelocEntry::apply(uint32_t *binary, const RelocInfo *info) const
{
   uint32_t value = 0;

   switch (type) {
   case TYPE_CODE: value = info->codePos; break;
   case TYPE_BUILTIN: value = info->libPos; break;
   case TYPE_DATA: value = info->dataPos; break;
   default:
      assert(0);
      break;
   }
   value += data;
   value = (bitPos < 0) ? (value >> -bitPos) : (value << bitPos);

   binary[offset / 4] &= ~mask;
   binary[offset / 4] |= value & mask;
}

} // namespace nv50_ir


#include "nv50/codegen/nv50_ir_driver.h"

extern "C" {

void
nv50_ir_relocate_code(void *relocData, uint32_t *code,
                      uint32_t codePos,
                      uint32_t libPos,
                      uint32_t dataPos)
{
   nv50_ir::RelocInfo *info = reinterpret_cast<nv50_ir::RelocInfo *>(relocData);

   info->codePos = codePos;
   info->libPos = libPos;
   info->dataPos = dataPos;

   for (unsigned int i = 0; i < info->count; ++i)
      info->entry[i].apply(code, info);
}

void
nv50_ir_get_target_library(uint32_t chipset,
                           const uint32_t **code, uint32_t *size)
{
   nv50_ir::Target *targ = nv50_ir::Target::create(chipset);
   targ->getBuiltinCode(code, size);
   nv50_ir::Target::destroy(targ);
}

}
