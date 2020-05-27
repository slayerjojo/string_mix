#include "mix.h"

#define MIX_FACTOR (3 * i + 7 + (size % 2))

int mix(uint8_t *src, uint32_t size)
{
    uint32_t i = 0;
    for (i = 0; i < size; i++)
    {
        if (!src[i])
            continue;

        src[i] = 1 + ((((uint32_t)src[i]) - 1 + MIX_FACTOR) % 0x100);
    }
    return 0;
}

int restore(uint8_t *src, uint32_t size)
{
    uint32_t i = 0;
    for (i = 0; i < size; i++)
    {
        if (!src[i])
            continue;

        if (src[i] > MIX_FACTOR)
            src[i] = src[i] - MIX_FACTOR;
        else
            src[i] = 0x100 - MIX_FACTOR + src[i];
    }
    return 0;
}
