#include "emulator_core.h"

int main()
{
    int init_status = core_init();
    if (init_status != 0)
    {
        return init_status;
    }

    core_run();

    core_shutdown();

    return 0;
}