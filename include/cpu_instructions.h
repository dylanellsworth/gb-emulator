#ifndef CPU_INSTRUCTIONS_H
#define CPU_INSTRUCTIONS_H

#include <stdint.h>

typedef struct {
    const char* disassembly;
    uint8_t opperand_length;
    void* execute;
} gb_cpu_instruction;

extern const gb_cpu_instruction instructions[256];

#endif