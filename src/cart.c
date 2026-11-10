#include <stdio.h>
#include "cart.h"

char runtime_path_buffer[256];
uint8_t cartridge_data[MAX_CART_SIZE];
cart_header* cartridge_header = (cart_header*)(cartridge_data + 0x100);
bool cartridge_loaded = false;

bool cart_load(const char* file_path)
{
    FILE *file = fopen(file_path, "rb");

    if (file == NULL) {
        perror("Error opening ROM file. Make sure the subdirectory and file exist");
        return false;
    }

    fread(cartridge_data, MAX_CART_SIZE, 1, file);

    fclose(file);

    return true;
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

    printf("ROM Size:\t\t\t%d\n", cartridge_header->rom_size);

    printf("RAM Size:\t\t\t%d\n", cartridge_header->ram_size);

    printf("Destination Code:\t\t%02X\n", cartridge_header->destination_code);

    printf("Old License Code:\t\t%02X\n", cartridge_header->old_license_code);

    printf("Mask ROM Version Number:\t%02X\n", cartridge_header->mask_rom_version_number);

    printf("Header Checksum:\t\t%02X\n", cartridge_header->header_checksum);

    printf("Global Checksum:\t\t%02X %02X\n",
    cartridge_header->global_checksum[0],
    cartridge_header->global_checksum[1]);
}