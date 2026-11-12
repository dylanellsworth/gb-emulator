#include "cpu_instructions.h"
#include "cpu.h"
#include <stddef.h>

const gb_cpu_instruction instructions[256] = {
    {"NOP", 0, cpu_noop}, // 0x00
    {"LD BC,u16", 2, NULL}, // 0x01
    {"LD (BC),A", 0, NULL}, // 0x02
    {"INC BC", 0, NULL}, // 0x03
    {"INC B", 0, NULL}, // 0x04
    {"DEC B", 0, NULL}, // 0x05
    {"LD B,u8", 1, NULL}, // 0x06
    {"RCLA", 0, NULL}, // 0x07
    {"LD (u16),SP", 2, NULL}, // 0x08
    {"ADD HL,BC", 0, NULL}, // 0x09
    {"LD A, (BC)", 0, NULL}, // 0x0A
    {"DEC BC", 0, NULL}, // 0x0B
    {"INC C", 0, NULL}, // 0x0C
    {"DEC C", 0, NULL}, // 0x0D
    {"LD C,u8", 1, NULL}, // 0x0E
    {"RRCA", 0, NULL}, // 0x0F
    {"STOP", 0, NULL}, // 0x10
    {"LD DE,u16", 1, NULL}, // 0x11
    {"LD (DE),A", 0, NULL}, // 0x12
    {"INC DE", 0, NULL}, // 0x13
    {"INC D", 0, NULL}, // 0x14
    {"DEC D", 0, NULL}, // 0x15
    {"LD D,u8", 0, NULL}, // 0x16
    {"RLA", 0, NULL}, // 0x17
    {"JR i8", 1, NULL}, // 0x18
    {"ADD HL,DE", 0, NULL}, // 0x19
    {"LD A,(DE)", 0, NULL}, // 0x1A
    {"DEC DE", 0, NULL}, // 0x1B
    {"INC E", 0, NULL}, // 0x1C
    {"DEC E", 0, NULL}, // 0x1D
    {"LD E,u8", 1, NULL}, // 0x1E
    {"RRA", 0, NULL}, // 0x1F
    {"JR NZ,i8", 1, NULL}, // 0x20
    {"LD HL,u16", 0, NULL}, // 0x21
    {"LD (HL+),A", 0, NULL}, // 0x22
    {"INC HL", 0, NULL}, // 0x23
    {"INC H", 0, NULL}, // 0x24
    {"DEC H", 0, NULL}, // 0x25
    {"LD H,u8", 0, NULL}, // 0x26
    {"DAA", 0, NULL}, // 0x27
    {"JR Z,i8", 1, NULL}, // 0x28
    {"ADD HL,HL", 0, NULL}, // 0x29
    {"LD A,(HL+)", 0, NULL}, // 0x2A
    {"DEC HL", 0, NULL}, // 0x2B
    {"INC L", 0, NULL}, // 0x2C
    {"DEC L", 0, NULL}, // 0x2D
    {"LD L,u8", 1, NULL}, // 0x2E
    {"CPL", 0, NULL}, // 0x2F
    {"JR NC,i8", 1, NULL}, // 0x30
    {"LD SP,u16",2, NULL}, // 0x31
    {"LD (HL-),A", 0, NULL}, // 0x32
    {"INC SP", 0, NULL}, // 0x33
    {"INC (HL)", 0, NULL}, // 0x34
    {"DEC (HL)", 0, NULL}, // 0x35
    {"LD (HL),u8", 1, NULL}, // 0x36
    {"SCF", 0, NULL}, // 0x37
    {"JF C,i8", 1, NULL}, // 0x38
    {"ADD HL,SP", 0, NULL}, // 0x39
    {"LD A,(HL-)", 0, NULL}, // 0x3A
    {"DEC SP", 0, NULL}, // 0x3B
    {"INC A", 0, NULL}, // 0x3C
    {"DEC A", 0, NULL}, // 0x3D
    {"LD A,u8", 0, NULL}, // 0x3E
    {"CCF", 0, NULL}, // 0x3F
    {"LD B,B", 0, NULL}, // 0x40
    {"LD B,C", 0, NULL}, // 0x41
    {"LD B,D", 0, NULL}, // 0x42
    {"LD B,E", 0, NULL}, // 0x43
    {"LD B,H", 0, NULL}, // 0x44
    {"LD B,L", 0, NULL}, // 0x45
    {"LD B,(HL)", 0, NULL}, // 0x46
    {"LD B,A", 0, NULL}, // 0x47
    {"LD C,B", 0, NULL}, // 0x48
    {"LD C,C", 0, NULL}, // 0x49
    {"LD C,D", 0, NULL}, // 0x4A
    {"LD C,E", 0, NULL}, // 0x4B
    {"LD C,H", 0, NULL}, // 0x4C
    {"LD C,L", 0, NULL}, // 0x4D
    {"LD C,(HL)", 0, NULL}, // 0x4E
    {"LD C,A", 0, NULL}, // 0x4F
    {"LD D,B", 0, NULL}, // 0x50
    {"LD D,C", 0, NULL}, // 0x51
    {"LD D,D", 0, NULL}, // 0x52
    {"LD D,E", 0, NULL}, // 0x53
    {"LD D,H", 0, NULL}, // 0x54
    {"LD D,L", 0, NULL}, // 0x55
    {"LD D,(HL)", 0, NULL}, // 0x56
    {"LD D,A", 0, NULL}, // 0x57
    {"LD E,B", 0, NULL}, // 0x58
    {"LD E,C", 0, NULL}, // 0x59
    {"LD E,D", 0, NULL}, // 0x5A
    {"LD E,E", 0, NULL}, // 0x5B
    {"LD E,H", 0, NULL}, // 0x5C
    {"LD E,L", 0, NULL}, // 0x5D
    {"LD E,(HL)", 0, NULL}, // 0x5E
    {"LD E,A", 0, NULL}, // 0x5F
    {"LD H,B", 0, NULL}, // 0x60
    {"LD H,C", 0, NULL}, // 0x61
    {"LD H,D", 0, NULL}, // 0x62
    {"LD H,E", 0, NULL}, // 0x63
    {"LD H,H", 0, NULL}, // 0x64
    {"LS H,L", 0, NULL}, // 0x65
    {"LD H,(HL)", 0, NULL}, // 0x66
    {"LD H,A", 0, NULL}, // 0x67
    {"LD L,B", 0, NULL}, // 0x68
    {"LD L,C", 0, NULL}, // 0x69
    {"LD L,D", 0, NULL}, // 0x6A
    {"LD L,E", 0, NULL}, // 0x6B
    {"LD L,H", 0, NULL}, // 0x6C
    {"LD L,L", 0, NULL}, // 0x6D
    {"LD L,(HL)", 0, NULL}, // 0x6E
    {"LD L,A", 0, NULL}, // 0x6F
    {"LD (HL),B", 0, NULL}, // 0x70
    {"LD (HL),C", 0, NULL}, // 0x71
    {"LD (HL),D", 0, NULL}, // 0x72
    {"LD (HL),E", 0, NULL}, // 0x73
    {"LD (HL),H", 0, NULL}, // 0x74
    {"LD (HL),L", 0, NULL}, // 0x75
    {"HALT", 0, NULL}, // 0x76
    {"LD (HL),A", 0, NULL}, // 0x77
    {"LD A,B", 0, NULL}, // 0x78
    {"LD A,C", 0, NULL}, // 0x79
    {"LD A,D", 0, NULL}, // 0x7A
    {"LD A,E", 0, NULL}, // 0x7B
    {"LD A,H", 0, NULL}, // 0x7C
    {"LD A,L", 0, NULL}, // 0x7D
    {"LD A,(HL)", 0, NULL}, // 0x7E
    {"LD A,A", 0, NULL}, // 0x7F
    {"ADD A,B", 0, NULL}, // 0x80
    {"ADD A,C", 0, NULL}, // 0x81
    {"ADD. A,D", 0, NULL}, // 0x82
    {"ADD A,E", 0, NULL}, // 0x83
    {"ADD A,H", 0, NULL}, // 0x84
    {"ADD A,L", 0, NULL}, // 0x85
    {"ADD A,(HL)", 0, NULL}, // 0x86
    {"ADD A,A", 0, NULL}, // 0x87
    {"ADC A,B", 0, NULL}, // 0x88
    {"ADC A,C", 0, NULL}, // 0x89
    {"ADC A,D", 0, NULL}, // 0x8A
    {"ADC A,E", 0, NULL}, // 0x8B
    {"ADC A,H", 0, NULL}, // 0x8C
    {"ADC A,L", 0, NULL}, // 0x8D
    {"ADC A,(HL)", 0, NULL}, // 0x8E
    {"ADC A,A", 0, NULL}, // 0x8F
    {"SUB A,B", 0, NULL}, // 0x90
    {"SUB A,C", 0, NULL}, // 0x91
    {"SUB A,D", 0, NULL}, // 0x92
    {"SUB A,E", 0, NULL}, // 0x93
    {"SUB A,H", 0, NULL}, // 0x94
    {"SUB A,L", 0, NULL}, // 0x95
    {"SUB A,(HL)", 0, NULL}, // 0x96
    {"SUB A,A", 0, NULL}, // 0x97
    {"SBC A,B", 0, NULL}, // 0x98
    {"SBC A,C", 0, NULL}, // 0x99
    {"SBC A,D", 0, NULL}, // 0x9A
    {"SBC A,E", 0, NULL}, // 0x9B
    {"SBC A,H", 0, NULL}, // 0x9C
    {"SBC A,L", 0, NULL}, // 0x9D
    {"SBC A,(HL)", 0, NULL}, // 0x9E
    {"SBC A,A", 0, NULL}, // 0x9F
    {"AND A,B", 0, NULL}, // 0xA0
    {"AND A,C", 0, NULL}, // 0xA1
    {"AND A,D", 0, NULL}, // 0xA2
    {"AND A,E", 0, NULL}, // 0xA3
    {"AND A,H", 0, NULL}, // 0xA4
    {"AND A,L", 0, NULL}, // 0xA5
    {"AND A,(HL)", 0, NULL}, // 0xA6
    {"AND A,A", 0, NULL}, // 0xA7
    {"XOR A,B", 0, NULL}, // 0xA8
    {"XOR A,C", 0, NULL}, // 0xA9
    {"XOR A,D", 0, NULL}, // 0xAA
    {"XOR A,E", 0, NULL}, // 0xAB
    {"XOR A,H", 0, NULL}, // 0xAC
    {"XOR A,L", 0, NULL}, // 0xAD
    {"XOR A,(HL)", 0, NULL}, // 0xAE
    {"XOR A,A", 0, cpu_xor_a}, // 0xAF
    {"OR A,B", 0, NULL}, // 0xB0
    {"OR A,C", 0, NULL}, // 0xB1
    {"OR A,D", 0, NULL}, // 0xB2
    {"OR A,E", 0, NULL}, // 0xB3
    {"OR A,H", 0, NULL}, // 0xB4
    {"OR A,L", 0, NULL}, // 0xB5
    {"OR A,(HL)", 0, NULL}, // 0xB6
    {"OR A,A", 0, NULL}, // 0xB7
    {"CP A,B", 0, NULL}, // 0xB8
    {"CP A,C", 0, NULL}, // 0xB9
    {"CP A,D", 0, NULL}, // 0xBA
    {"CP A,E", 0, NULL}, // 0xBB
    {"CP A,H", 0, NULL}, // 0xBC
    {"CP A,L", 0, NULL}, // 0xBD
    {"CP A (HL)", 0, NULL}, // 0xBE
    {"CP A,A", 0, NULL}, // 0xBF
    {"RET NZ", 0, NULL}, // 0xC0
    {"POP BC", 0, NULL}, // 0xC1
    {"JP NZ,u16", 2, NULL}, // 0xC2
    {"JP u16", 2, cpu_jp_u16}, // 0xC3
    {"CALL NZ,u16", 2, NULL}, // 0xC4
    {"PUSH BC", 0, NULL}, // 0xC5
    {"ADD A,u8", 1, NULL}, // 0xC6
    {"RST 00h", 0, NULL}, // 0xC7
    {"RET Z", 0, NULL}, // 0xC8
    {"RET", 0, NULL}, // 0xC9
    {"JP Z,u16", 2, NULL}, // 0xCA
    {"PREFIX CB", 0, NULL}, // 0xCB
    {"CALL Z,u16", 2, NULL}, // 0xCC
    {"CALL u16", 2, NULL}, // 0xCD
    {"ADC A,u8", 1, NULL}, // 0xCE
    {"RST 08h", 0, NULL}, // 0xCF
    {"RET NC", 0, NULL}, // 0xD0
    {"POP DE", 0, NULL}, // 0xD1
    {"JP NC,u16", 0, NULL}, // 0xD2
    {"INVALID", 0, NULL}, // 0xD3
    {"CALL NC,u16", 2, NULL}, // 0xD4
    {"PUSH DE", 0, NULL}, // 0xD5
    {"SUB A,u8", 1, NULL}, // 0xD6
    {"RST 10h", 0, NULL}, // 0xD7
    {"RET C", 0, NULL}, // 0xD8
    {"RETI", 0, NULL}, // 0xD9
    {"JP C,u16", 2, NULL}, // 0xDA
    {"INVALID", 0, NULL}, // 0xDB
    {"CALL C,u16", 2, NULL}, // 0xDC
    {"INVALID", 0, NULL}, // 0xDD
    {"SBC A,u8", 1, NULL}, // 0xDE
    {"RST 18h", 0, NULL}, // 0xDF
    {"LD (FF00+u8),A", 0, NULL}, // 0xE0
    {"POP HL", 0, NULL}, // 0xE1
    {"LD (FF00+C),A", 0, NULL}, // 0xE2
    {"INVALID", 0, NULL}, // 0xE3
    {"INVALID", 0, NULL}, // 0xE4
    {"PUSH HL", 0, NULL}, // 0xE5
    {"AND A,u8", 0, NULL}, // 0xE6
    {"RST 20h", 0, NULL}, // 0xE7
    {"ADD SP,i8", 1, NULL}, // 0xE8
    {"JP HL", 0, NULL}, // 0xE9
    {"LD (u16), A", 1, NULL}, // 0xEA
    {"INVALID", 0, NULL}, // 0xEB
    {"INVALID", 0, NULL}, // 0xEC
    {"INVALID", 0, NULL}, // 0xED
    {"XOR A,u8", 1, NULL}, // 0xEE
    {"RST 28h", 0, NULL}, // 0xEF
    {"LD A,(FF00+u8)", 0, NULL}, // 0xF0
    {"POP AF", 0, NULL}, // 0xF1
    {"LD A,(FF00+C)", 0, NULL}, // 0xF2
    {"DI", 0, NULL}, // 0xF3
    {"INVALID", 0, NULL}, // 0xF4
    {"PUSH AF", 0, NULL}, // 0xF5
    {"OR A,u8", 0, NULL}, // 0xF6
    {"RST 30h", 0, NULL}, // 0xF7
    {"LD HL,SP+i8", 1, NULL}, // 0xF8
    {"LD SP,HL", 0, NULL}, // 0xF9
    {"LD A,(u16)", 2, NULL}, // 0xFA
    {"EI", 0, NULL}, // 0xFB
    {"INVALID", 0, NULL}, // 0xFC
    {"INVALID", 0, NULL}, // 0xFD
    {"CP A,u8", 1, NULL}, // 0xFE
    {"RST 38h", 0, NULL}  // 0xFF
};