#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    union {
        struct {
            uint8_t f; // Flags
            uint8_t a; // Accumulator
        };
        uint16_t af;
    };


    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };


    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };

    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };

    uint16_t sp; // Stack Pointer
    
    uint16_t pc; // Program Counter
} gb_cpu_registers;

typedef void (*cpu_execute_op)();

extern gb_cpu_registers cpu_registers;

void cpu_reset();
void cpu_fetch_instruction();
bool cpu_execute_instruction();

// CPU Operations
void cpu_noop(); // 0x00

#endif // CPU_H