#ifndef EMULATOR_CORE_H
#define EMULATOR_CORE_H

#include <stdint.h>

extern uint32_t core_clock_counter;

int core_init(const char* rom_path);
void core_run();
void core_shutdown();

void core_advance_clocks(uint8_t ticks);

#endif