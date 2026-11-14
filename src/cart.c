#include <stdio.h>
#include "cart.h"

char runtime_path_buffer[256];
uint8_t cartridge_data[MAX_CART_SIZE];
cart_header* cartridge_header = (cart_header*)(cartridge_data + 0x100);
bool cartridge_loaded = false;
uint32_t cartridge_rom_size = 0;

bool cart_load(const char* file_path)
{
    FILE *file = fopen(file_path, "rb");

    if (file == NULL) {
        perror("Error opening ROM file. Make sure the subdirectory and file exist");
        return false;
    }

    fread(cartridge_data, MAX_CART_SIZE, 1, file);

    if (!cart_validate_header_checksum())
    {
        perror("Error validating ROM file. Header checksum failure");
        return false;
    }

    switch(cartridge_header->rom_size)
    {
        case KB32:
            cartridge_rom_size = 32 * 1024;
            break;
        case KB64:
            cartridge_rom_size = 64 * 1024;
            break;
        case KB128:
            cartridge_rom_size = 128 * 1024;
            break;
        case KB512:
            cartridge_rom_size = 512 * 1024;
            break;
        case MB1:
            cartridge_rom_size = 1024 * 1024;
            break;
        case MB2:
            cartridge_rom_size = 2 * 1024 * 1024;
            break;
        case MB4:
            cartridge_rom_size = 4 * 1024 * 1024;
            break;
        case MB8:
            cartridge_rom_size = 8 * 1024 * 1024;
            break;
    }

    if (!cart_validate_global_checksum())
    {
        perror("Error validating ROM file. Global checksum failure");
        return false;
    }

    fclose(file);

    return true;
}

bool cart_validate_header_checksum()
{
    uint8_t checksum = 0;
    for (uint16_t address = 0x0134; address <= 0x014C; address++)
    {
        checksum = checksum - cartridge_data[address] - 1;
    }

    return (cartridge_header->header_checksum == checksum);
}

bool cart_validate_global_checksum()
{
    // global checksum is the sum of all bytes in the ROM
    uint16_t checksum = 0;
    uint32_t i;
    for (i=0; i<cartridge_rom_size; i++)
    {
        // Exclude the global checksum bytes themselves
        if ((i != 0x14E) && (i != 0x14F))
        {
            checksum += cartridge_data[i];
        }
    }

    // get the global checksum as reported by the cart header
    uint16_t reported_checksum = (cartridge_header->global_checksum[0] << 8) | (cartridge_header->global_checksum[1]);

    return (reported_checksum == checksum);
}

void cart_print_info()
{
    printf("Entrypoint:\t\t\t%02X %02X %02X %02X\n",
    cartridge_header->entrypoint[0],
    cartridge_header->entrypoint[1],
    cartridge_header->entrypoint[2],
    cartridge_header->entrypoint[3]);

    printf("Title:\t\t\t\t%s\n", cartridge_header->title);

    printf("CGB Flag:\t\t\t%d\n", cartridge_header->cgb_flag);

    printf("New License Code:\t\t%02X %02X\n",
    cartridge_header->new_license_code[0],
    cartridge_header->new_license_code[1]);

    printf("SGB Flag:\t\t\t%d\n", cartridge_header->sgb_flag);

    printf("Cartridge Type:\t\t\t%02X\n", cartridge_header->cartrige_type);

    printf("ROM Size:\t\t\t%d (%d bytes)\n", cartridge_header->rom_size, cartridge_rom_size);

    printf("RAM Size:\t\t\t%d\n", cartridge_header->ram_size);

    printf("Destination Code:\t\t%02X\n", cartridge_header->destination_code);

    printf("Old License Code:\t\t%02X\n", cartridge_header->old_license_code);

    printf("Mask ROM Version Number:\t%02X\n", cartridge_header->mask_rom_version_number);

    printf("Header Checksum:\t\t%02X\n", cartridge_header->header_checksum);

    printf("Global Checksum:\t\t%02X %02X\n",
    cartridge_header->global_checksum[0],
    cartridge_header->global_checksum[1]);
}