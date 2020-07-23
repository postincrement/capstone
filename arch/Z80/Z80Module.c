/* Capstone Disassembly Engine */
/* Z80 Backend by Craig Southeren <craig@postincrement.com> 2020 */

#ifdef CAPSTONE_HAS_Z80

#include "../../utils.h"
#include "../../MCRegisterInfo.h"
#include "Z80Disassembler.h"
#include "Z80Module.h"

cs_err Z80_global_init(cs_struct *ud)
{
	// verify if requested mode is valid
	if (ud->mode)
		return CS_ERR_MODE;

	ud->printer = Z80_printInst;
	ud->printer_info = NULL;
	ud->insn_id = Z80_get_insn_id;
	ud->insn_name = Z80_insn_name;
	ud->group_name = Z80_group_name;
	ud->disasm = Z80_getInstruction;
	ud->reg_name = Z80_reg_name;

	return CS_ERR_OK;
}

cs_err Z80_option(cs_struct *handle, cs_opt_type type, size_t value)
{
	return CS_ERR_OK;
}

#endif
