#ifndef __MIX_H__
#define __MIX_H__

#include <stdint.h>

int mix(uint8_t *src, uint32_t size, const char *charset);
int restore(uint8_t *src, uint32_t size, const char *charset);

#endif
