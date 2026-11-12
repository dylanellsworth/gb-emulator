#include "emulator_core.h"
#include "cart.h"
#include "cpu.h"

const char* rom_path = "roms/links-awakening.gb";

uint32_t core_clock_counter = 0;
bool core_quit_requested = false;

int core_init()
{
    if (!cart_load(rom_path))
    {
        return -1;
    }

    cart_print_info();

    return 0;
}

void core_run()
{
    cpu_reset();

    while (!core_quit_requested)
    {
        cpu_fetch_instruction();
        if (!cpu_execute_instruction())
        {
            core_quit_requested = true;
        }
    }
}

void core_shutdown()
{
}

void core_advance_clocks(uint8_t ticks)
{
    core_clock_counter += ticks;
}