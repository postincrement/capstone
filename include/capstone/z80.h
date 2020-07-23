#ifndef CAPSTONE_Z80_H
#define CAPSTONE_Z80_H

/* Capstone Disassembly Engine */
/* Z80 Backend by Craig Southeren <craig@postincrement.com> 2020 */

#ifdef __cplusplus
extern "C" {
#endif

#include "platform.h"

/// Z80 registers and special registers
typedef enum z80_reg {
	Z80_REG_INVALID = 0,
	Z80_REG_A, ///< accumulator
	Z80_REG_B, ///< accumulator
	Z80_REG_X, ///< X index register
	Z80_REG_Y, ///< Y index register
	Z80_REG_P, ///< status register
	Z80_REG_SP, ///< stack pointer register
	Z80_REG_ENDING,   // <-- mark the end of the list of registers
} z80_reg;

/// Z80 Addressing Modes
typedef enum z80_address_mode {
	Z80_AM_NONE = 0, ///< No address mode.
	Z80_AM_IMP, ///< implied addressing (no addressing mode)
	Z80_AM_ACC, ///< accumulator addressing
	Z80_AM_ABS, ///< absolute addressing
	Z80_AM_ZP,  ///< zeropage addressing
	Z80_AM_IMM, ///< 8 Bit immediate value
	Z80_AM_ABSX, ///< indexed absolute addressing by the X index register
	Z80_AM_ABSY, ///< indexed absolute addressing by the Y index register
	Z80_AM_INDX, ///< indexed indirect addressing by the X index register
	Z80_AM_INDY, ///< indirect indexed addressing by the Y index register
	Z80_AM_ZPX, ///< indexed zeropage addressing by the X index register
	Z80_AM_ZPY, ///< indexed zeropage addressing by the Y index register
	Z80_AM_REL, ///< relative addressing used by branches
	Z80_AM_IND, ///< absolute indirect addressing
} z80_address_mode;

/// Z80 instruction
typedef enum z80_insn {
	Z80_INS_INVALID = 0,
	Z80_INS_ADC,
	Z80_INS_AND,
	Z80_INS_ASL,
	Z80_INS_BCC,
	Z80_INS_BCS,
	Z80_INS_BEQ,
	Z80_INS_BIT,
	Z80_INS_BMI,
	Z80_INS_BNE,
	Z80_INS_BPL,
	Z80_INS_BRK,
	Z80_INS_BVC,
	Z80_INS_BVS,
	Z80_INS_CLC,
	Z80_INS_CLD,
	Z80_INS_CLI,
	Z80_INS_CLV,
	Z80_INS_CMP,
	Z80_INS_CPX,
	Z80_INS_CPY,
	Z80_INS_DEC,
	Z80_INS_DEX,
	Z80_INS_DEY,
	Z80_INS_EOR,
	Z80_INS_INC,
	Z80_INS_INX,
	Z80_INS_INY,
	Z80_INS_JMP,
	Z80_INS_JSR,
	Z80_INS_LDA,
	Z80_INS_LDX,
	Z80_INS_LDY,
	Z80_INS_LSR,
	Z80_INS_NOP,
	Z80_INS_ORA,
	Z80_INS_PHA,
	Z80_INS_PLA,
	Z80_INS_PHP,
	Z80_INS_PLP,
	Z80_INS_ROL,
	Z80_INS_ROR,
	Z80_INS_RTI,
	Z80_INS_RTS,
	Z80_INS_SBC,
	Z80_INS_SEC,
	Z80_INS_SED,
	Z80_INS_SEI,
	Z80_INS_STA,
	Z80_INS_STX,
	Z80_INS_STY,
	Z80_INS_TAX,
	Z80_INS_TAY,
	Z80_INS_TSX,
	Z80_INS_TXA,
	Z80_INS_TXS,
	Z80_INS_TYA,
	Z80_INS_ENDING,   // <-- mark the end of the list of instructions
} z80_insn;

/// Group of Z80 instructions
typedef enum z80_group_type {
	Z80_GRP_INVALID = 0,  ///< CS_GRP_INVALID
	Z80_GRP_JUMP,		 ///< = CS_GRP_JUMP
	Z80_GRP_CALL,		 ///< = CS_GRP_RET
	Z80_GRP_RET,		  ///< = CS_GRP_RET
	Z80_GRP_IRET = 5,	 ///< = CS_GRP_IRET
	Z80_GRP_BRANCH_RELATIVE = 6, ///< = CS_GRP_BRANCH_RELATIVE
	Z80_GRP_ENDING,// <-- mark the end of the list of groups
} z80_group_type;

/// Operand type for instruction's operands
typedef enum z80_op_type {
	Z80_OP_INVALID = 0, ///< = CS_OP_INVALID (Uninitialized).
	Z80_OP_REG, ///< = CS_OP_REG (Register operand).
	Z80_OP_IMM, ///< = CS_OP_IMM (Immediate operand).
	Z80_OP_MEM, ///< = CS_OP_MEM (Memory operand).
} z80_op_type;

/// Instruction operand
typedef struct cs_z80_op {
	z80_op_type type;	///< operand type
	union {
		z80_reg reg;	///< register value for REG operand
		uint8_t imm;		///< immediate value for IMM operand
		uint16_t mem;		///< base/index/scale/disp value for MEM operand
	};
} cs_z80_op;

/// The Z80 address mode and it's operands
typedef struct cs_z80 {
	z80_address_mode am;
	bool modifies_flags;

	/// Number of operands of this instruction,
	/// or 0 when instruction has no operand.
	uint8_t op_count;
	cs_z80_op operands[3]; ///< operands for this instruction.
} cs_z80;

#ifdef __cplusplus
}
#endif

#endif //CAPSTONE_Z80_H
