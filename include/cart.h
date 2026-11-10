#include <stdint.h>
#include <stdbool.h>

#ifndef CART_H
#define CART_H

#define MAX_CART_SIZE  (8 * 1024 * 1024)
extern uint8_t cartridge_data[MAX_CART_SIZE];
extern bool cartridge_loaded;

typedef struct
{
    uint8_t entrypoint[4];
    uint8_t nintendo_logo[48];
    uint8_t title[15];
    uint8_t cgb_flag;
    uint8_t new_license_code[2];
    uint8_t sgb_flag;
    uint8_t cartrige_type;
    uint8_t rom_size;
    uint8_t ram_size;
    uint8_t destination_code;
    uint8_t old_license_code;
    uint8_t mask_rom_version_number;
    uint8_t header_checksum;
    uint8_t global_checksum[2];
} cart_header;

extern cart_header* cartridge_header;

bool cart_load(const char*s);
void cart_print_info();

#endif //CART_H
