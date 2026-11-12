#include "cpu.h"
#include "cpu_instructions.h"
#include "emulator_core.h"
#include "memory_bus.h"
#include <stddef.h>
#include <stdio.h>

gb_cpu_registers cpu_registers;
uint8_t cpu_current_op_code = 0;
uint32_t cpu_instuction_counter = 0;
void* cpu_current_instruction_execute = NULL;

void cpu_reset()
{
    // After boot rom, registers should have these values
    cpu_registers.af = 0x01B0;
    cpu_registers.bc = 0x0013;
    cpu_registers.de = 0x00D8;
    cpu_registers.hl = 0x014D;
    cpu_registers.sp = 0xFFFE;
    cpu_registers.pc = 0x0100;
}

void cpu_fetch_instruction()
{
    // TODO: Read from memory bus instead of directly from ROM data
    cpu_current_op_code = memory_bus_read(cpu_registers.pc++);
    const gb_cpu_instruction* instruction = &instructions[cpu_current_op_code];
    cpu_current_instruction_execute = instruction->execute;
}

bool cpu_execute_instruction()
{
    // Undefined instruction
    if (!cpu_current_instruction_execute)
    {
        const gb_cpu_instruction* instruction = &instructions[cpu_current_op_code];
        const uint8_t pchi = ((cpu_registers.pc-1) & 0xFF00) >> 8;
        const uint8_t pclo = ((cpu_registers.pc-1) & 0xFF);
        printf("Unknown instruction %02X at %02X%02X (%s), count: %i\n", cpu_current_op_code, pchi, pclo, instruction->disassembly, cpu_instuction_counter);
        return false;
    }

    // Execute the instruction
    ((cpu_execute_op)cpu_current_instruction_execute)();
    return true;
}

void cpu_noop()
{
    core_advance_clocks(4);
}

void cpu_jp_u16()
{
    core_advance_clocks(4);
    // Get jump address MSB
    uint32_t temp = memory_bus_read(cpu_registers.pc++);
    cpu_registers.pc &= 0xFFFF;
    core_advance_clocks(4);
    // get jump address LSB
    temp |= ((uint32_t)memory_bus_read(cpu_registers.pc++)) << 8;
    cpu_registers.pc &= 0xFFFF;
    core_advance_clocks(4);
    // Set PC to jump address
    cpu_registers.pc = temp;
    core_advance_clocks(4);
}

void cpu_xor_a()
{
    cpu_registers.a = 0;
    SET_FLAG_SUBTRACT(0);
    SET_FLAG_CARRY(0);
    SET_FLAG_HALF_CARRY(0);
    SET_FLAG_ZERO(1);
    core_advance_clocks(4);
}
