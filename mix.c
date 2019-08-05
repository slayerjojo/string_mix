#include "mix.h"
#include <string.h>
#include <stdio.h>

#define MIX_FACTOR ((3 * i + 7 + (size % 2)) % length)

int mix(uint8_t *src, uint32_t size, const char *charset)
{
    uint32_t length = strlen(charset);
    uint32_t i = 0;
    for (i = 0; i < size; i++)
    {
        char pin[2] = {0};
        pin[0] = src[i];
        char *p = strstr(charset, pin);
        if (!p)
            return -1;
        src[i] = charset[(p - charset + MIX_FACTOR) % length];
    }
    return 0;
}

int restore(uint8_t *src, uint32_t size, const char *charset)
{
    uint32_t length = strlen(charset);
    uint32_t i = 0;
    for (i = 0; i < size; i++)
    {
        char pin[2] = {0};
        pin[0] = src[i];
        char *p = strstr(charset, pin);
        if (!p)
            return -1;
        if (p - charset > MIX_FACTOR)
            src[i] = charset[p - charset - MIX_FACTOR];
        else
            src[i] = charset[(length - MIX_FACTOR + (p - charset)) % length];
    }
    return 0;
}
