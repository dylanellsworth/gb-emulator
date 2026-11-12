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
    {"???", 0, NULL}, // 0x80
    {"???", 0, NULL}, // 0x81
    {"???", 0, NULL}, // 0x82
    {"???", 0, NULL}, // 0x83
    {"???", 0, NULL}, // 0x84
    {"???", 0, NULL}, // 0x85
    {"???", 0, NULL}, // 0x86
    {"???", 0, NULL}, // 0x87
    {"???", 0, NULL}, // 0x88
    {"???", 0, NULL}, // 0x89
    {"???", 0, NULL}, // 0x8A
    {"???", 0, NULL}, // 0x8B
    {"???", 0, NULL}, // 0x8C
    {"???", 0, NULL}, // 0x8D
    {"???", 0, NULL}, // 0x8E
    {"???", 0, NULL}, // 0x8F
    {"???", 0, NULL}, // 0x90
    {"???", 0, NULL}, // 0x91
    {"???", 0, NULL}, // 0x92
    {"???", 0, NULL}, // 0x93
    {"???", 0, NULL}, // 0x94
    {"???", 0, NULL}, // 0x95
    {"???", 0, NULL}, // 0x96
    {"???", 0, NULL}, // 0x97
    {"???", 0, NULL}, // 0x98
    {"???", 0, NULL}, // 0x99
    {"???", 0, NULL}, // 0x9A
    {"???", 0, NULL}, // 0x9B
    {"???", 0, NULL}, // 0x9C
    {"???", 0, NULL}, // 0x9D
    {"???", 0, NULL}, // 0x9E
    {"???", 0, NULL}, // 0x9F
    {"???", 0, NULL}, // 0xA0
    {"???", 0, NULL}, // 0xA1
    {"???", 0, NULL}, // 0xA2
    {"???", 0, NULL}, // 0xA3
    {"???", 0, NULL}, // 0xA4
    {"???", 0, NULL}, // 0xA5
    {"???", 0, NULL}, // 0xA6
    {"???", 0, NULL}, // 0xA7
    {"???", 0, NULL}, // 0xA8
    {"???", 0, NULL}, // 0xA9
    {"???", 0, NULL}, // 0xAA
    {"???", 0, NULL}, // 0xAB
    {"???", 0, NULL}, // 0xAC
    {"???", 0, NULL}, // 0xAD
    {"???", 0, NULL}, // 0xAE
    {"???", 0, NULL}, // 0xAF
    {"???", 0, NULL}, // 0xB0
    {"???", 0, NULL}, // 0xB1
    {"???", 0, NULL}, // 0xB2
    {"???", 0, NULL}, // 0xB3
    {"???", 0, NULL}, // 0xB4
    {"???", 0, NULL}, // 0xB5
    {"???", 0, NULL}, // 0xB6
    {"???", 0, NULL}, // 0xB7
    {"???", 0, NULL}, // 0xB8
    {"???", 0, NULL}, // 0xB9
    {"???", 0, NULL}, // 0xBA
    {"???", 0, NULL}, // 0xBB
    {"???", 0, NULL}, // 0xBC
    {"???", 0, NULL}, // 0xBD
    {"???", 0, NULL}, // 0xBE
    {"???", 0, NULL}, // 0xBF
    {"???", 0, NULL}, // 0xC0
    {"???", 0, NULL}, // 0xC1
    {"???", 0, NULL}, // 0xC2
    {"JP u16", 0, cpu_jp_u16}, // 0xC3
    {"???", 0, NULL}, // 0xC4
    {"???", 0, NULL}, // 0xC5
    {"???", 0, NULL}, // 0xC6
    {"???", 0, NULL}, // 0xC7
    {"???", 0, NULL}, // 0xC8
    {"???", 0, NULL}, // 0xC9
    {"???", 0, NULL}, // 0xCA
    {"???", 0, NULL}, // 0xCB
    {"???", 0, NULL}, // 0xCC
    {"CALL u16", 0, NULL}, // 0xCD
    {"???", 0, NULL}, // 0xCE
    {"???", 0, NULL}, // 0xCF
    {"???", 0, NULL}, // 0xD0
    {"???", 0, NULL}, // 0xD1
    {"???", 0, NULL}, // 0xD2
    {"???", 0, NULL}, // 0xD3
    {"???", 0, NULL}, // 0xD4
    {"???", 0, NULL}, // 0xD5
    {"???", 0, NULL}, // 0xD6
    {"???", 0, NULL}, // 0xD7
    {"???", 0, NULL}, // 0xD8
    {"???", 0, NULL}, // 0xD9
    {"???", 0, NULL}, // 0xDA
    {"???", 0, NULL}, // 0xDB
    {"???", 0, NULL}, // 0xDC
    {"???", 0, NULL}, // 0xDD
    {"???", 0, NULL}, // 0xDE
    {"???", 0, NULL}, // 0xDF
    {"???", 0, NULL}, // 0xE0
    {"???", 0, NULL}, // 0xE1
    {"???", 0, NULL}, // 0xE2
    {"???", 0, NULL}, // 0xE3
    {"???", 0, NULL}, // 0xE4
    {"???", 0, NULL}, // 0xE5
    {"???", 0, NULL}, // 0xE6
    {"???", 0, NULL}, // 0xE7
    {"???", 0, NULL}, // 0xE8
    {"???", 0, NULL}, // 0xE9
    {"???", 0, NULL}, // 0xEA
    {"???", 0, NULL}, // 0xEB
    {"???", 0, NULL}, // 0xEC
    {"???", 0, NULL}, // 0xED
    {"???", 0, NULL}, // 0xEE
    {"???", 0, NULL}, // 0xEF
    {"???", 0, NULL}, // 0xF0
    {"???", 0, NULL}, // 0xF1
    {"???", 0, NULL}, // 0xF2
    {"???", 0, NULL}, // 0xF3
    {"???", 0, NULL}, // 0xF4
    {"???", 0, NULL}, // 0xF5
    {"???", 0, NULL}, // 0xF6
    {"???", 0, NULL}, // 0xF7
    {"???", 0, NULL}, // 0xF8
    {"???", 0, NULL}, // 0xF9
    {"???", 0, NULL}, // 0xFA
    {"???", 0, NULL}, // 0xFB
    {"???", 0, NULL}, // 0xFC
    {"???", 0, NULL}, // 0xFD
    {"???", 0, NULL}, // 0xFE
    {"???", 0, NULL}  // 0xFF
};