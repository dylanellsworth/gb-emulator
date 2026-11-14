#include "emulator_core.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    int init_status = core_init(argv[1]);
    if (init_status != 0)
    {
        return init_status;
    }

    core_run();

    core_shutdown();

    return 0;
}