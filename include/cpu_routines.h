#ifndef CPU_ROUTINES_H
#define CPU_ROUTINES_H

#include <stdint.h>

#define cpu_routine_ld_8(reg)                      \
{                                                  \
    core_advance_clocks(4);                        \
    reg = memory_bus_read(cpu_registers.pc++);     \
    core_advance_clocks(4);                        \
}

#define cpu_routine_ld_16(reg_hi, reg_low)         \
{                                                  \
    core_advance_clocks(4);                        \
    reg_low = memory_bus_read(cpu_registers.pc++); \
    core_advance_clocks(4);                        \
    reg_hi = memory_bus_read(cpu_registers.pc++);  \
    core_advance_clocks(4);                        \
}

#define cpu_routine_inc_16(reg16)					\
{													\
	core_advance_cpu_clocks(4);						\
	reg16 = (reg16 + 1);							\
	core_advance_clocks(4);                         \
}

#define cpu_routine_dec_16(reg16)					\
{													\
	core_advance_cpu_clocks(4);						\
	reg16 = (reg16 - 1);							\
	core_advance_clocks(4);				            \
}

#define cpu_routine_inc_8(reg8)						\
{													\
	SET_FLAG_SUBTRACT(0);							\
	SET_FLAG_HALF_CARRY((reg8 & 0xF) == 0xF);		\
	reg8++;											\
	SET_FLAG_ZERO(reg8 == 0);						\
	core_advance_clocks(4);				            \
}

#define cpu_routine_dec_8(reg8)						\
{													\
	SET_FLAG_SUBTRACT(1);							\
	SET_FLAG_HALF_CARRY((reg8 & 0xF) == 0x0);		\
	reg8--;											\
	SET_FLAG_ZERO(reg8 == 0);						\
	core_advance_clocks(4);				            \
}

#define cpu_routine_jr_conditional_n(cond)									\
{																			\
	core_advance_clocks(4);												    \
	if (cond)																\
	{																		\
		uint8_t temp = memory_bus_read(cpu_registers.pc++);					\
		core_advance_clocks(4);											    \
		cpu_registers.pc = (cpu_registers.pc + (int8_t)temp) & 0xFFFF;		\
		core_advance_clocks(4);											    \
	}																		\
	else																	\
	{																		\
		cpu_registers.pc++;													\
		core_advance_clocks(4);		    									\
	}																		\
}

#endif