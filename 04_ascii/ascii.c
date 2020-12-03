#include "stdio.h"

int main(void)
{
    char c;
    for (c = 33; c <= 126; c++)
    {
        putchar(c);
        printf(", dec: %d", c);
        printf(", hex: %x", c);
        printf(", oct: %o\n", c);
    }

    return 0;
}
