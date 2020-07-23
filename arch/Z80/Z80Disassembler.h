/* Capstone Disassembly Engine */
/* Z80 Backend by Craig Southeren <craig@postincrement.com> 2020 */

#ifndef CAPSTONE_Z80DISASSEMBLER_H
#define CAPSTONE_Z80DISASSEMBLER_H

#include "../../utils.h"

void Z80_printInst(MCInst *MI, struct SStream *O, void *PrinterInfo);

void Z80_get_insn_id(cs_struct *h, cs_insn *insn, unsigned int id);

const char *Z80_insn_name(csh handle, unsigned int id);

const char *Z80_group_name(csh handle, unsigned int id);

const char* Z80_reg_name(csh handle, unsigned int reg);

bool Z80_getInstruction(csh ud, const uint8_t *code, size_t code_len,
                            MCInst *MI, uint16_t *size, uint64_t address, void *inst_info);

#endif //CAPSTONE_Z80DISASSEMBLER_H
