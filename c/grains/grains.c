#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64) return 0;
    uint64_t output = 1;
    return output << (index - 1);
}

uint64_t total()
{
    uint64_t output = 0;
    for (uint8_t i = 0; i < 64; ++i)
    {
        output += (uint64_t)1 << i;
    }
    return output;
}