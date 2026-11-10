#include "cart.h"
#include "cpu.h"

const char* rom_path = "roms/links-awakening.gb";

int main()
{
    if (cart_load(rom_path))
    {
        cart_print_info();
    }

    cpu_reset();
    cpu_fetch_instruction();
    cpu_execute_instruction();

    return 0;
}