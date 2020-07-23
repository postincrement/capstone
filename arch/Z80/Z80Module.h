/* Capstone Disassembly Engine */
/* Z80 Backend by Craig Southeren <craig@postincrement.com> 2020 */

#ifndef CS_Z80_MODULE_H
#define CS_Z80_MODULE_H

#include "../../utils.h"

cs_err Z80_global_init(cs_struct *ud);
cs_err Z80_option(cs_struct *handle, cs_opt_type type, size_t value);

#endif
