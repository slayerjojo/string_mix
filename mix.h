#ifndef __MIX_H__
#define __MIX_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int mix(uint8_t *src, uint32_t size);
int restore(uint8_t *src, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif
