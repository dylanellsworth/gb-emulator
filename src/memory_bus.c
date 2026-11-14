#include "memory_bus.h"
#include "cart.h"

uint8_t memory[MEMORY_SIZE];

uint8_t memory_bus_read(const uint16_t addr)
{
    return cartridge_data[addr];
}

void memory_bus_write(const uint16_t addr, const uint8_t val)
{
    if ((addr < 0) || (addr > MEMORY_SIZE - 1))
    {
        return;
    }

    memory[addr] = val;
}
