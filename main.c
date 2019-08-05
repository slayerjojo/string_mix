#include <string.h>
#include <stdio.h>
#include "mix.h"

int main(int argc, char *argv[])
{
    char *seed = "abcdefghijkmnlopqrstuvwxyz0123456789ABCDEFGHIJKMNLOPQRSTUVWXYZ";
    printf("raw:%s\r\n", argv[1]);
    mix((uint8_t *)argv[1], strlen(argv[1]), seed);
    printf("mix:%s\r\n", argv[1]);
    restore((uint8_t *)argv[1], strlen(argv[1]), seed);
    printf("restore:%s\r\n", argv[1]);
    return 0;
}
