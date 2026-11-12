#ifndef CPU_ROUTINES_H
#define CPU_ROUTINES_H

#include <stdint.h>

#define cpu_routine_ld_8(reg)                      \
{                                                  \
    core_advance_cpu_clocks(4);                    \
    reg = memory_bus_read(cpu_registers.pc++);     \
    core_advance_cpu_clocks(4);                    \
}

#define cpu_routine_ld_16(reg_hi, reg_low)         \
{                                                  \
    core_advance_cpu_clocks(4);                    \
    reg_low = memory_bus_read(cpu_registers.pc++); \
    core_advance_cpu_clocks(4);                    \
    reg_hi = memory_bus_read(cpu_registers.pc++);  \
    core_advance_cpu_clocks(4);                    \
}

#endif