#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdbool.h>

#define SET_FLAG_ZERO(value)        cpu_registers.f = (cpu_registers.f & ~(1UL << 7)) | ((value) << 7);
#define GET_FLAG_ZERO               ((cpu_registers.f & ~(1UL << 7)) >> 7)
#define SET_FLAG_SUBTRACT(value)    cpu_registers.f = (cpu_registers.f & ~(1UL << 7)) | ((value) << 6);
#define GET_FLAG_SUBTRACT           ((cpu_registers.f & ~(1UL << 7)) >> 6)
#define SET_FLAG_HALF_CARRY(value)  cpu_registers.f = (cpu_registers.f & ~(1UL << 7)) | ((value) << 5);
#define GET_FLAG_HALF_CARRY         ((cpu_registers.f & ~(1UL << 7)) >> 5)
#define SET_FLAG_CARRY(value)       cpu_registers.f = (cpu_registers.f & ~(1UL << 7)) | ((value) << 4);
#define GET_FLAG_CARRY              ((cpu_registers.f & ~(1UL << 7)) >> 4)

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
void cpu_noop();      // 0x00
void cpu_dec_b();     // 0x05
void cpu_ld_b_u8();   // 0x06
void cpu_ld_c_u8();   // 0x0E
void cpu_jr_nz_i8();  // 0x20
void cpu_ld_hl_u16(); // 0x21
void cpu_ldd_hl_a();  // 0x32
void cpu_xor_a();     // 0xAF
void cpu_jp_u16();    // 0xC3

#endif // CPU_H