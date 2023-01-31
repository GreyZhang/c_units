#include <stdint.h>
#include <stdio.h>

int hacker_popcnt(uint32_t n)
{
    n -= (n >> 1) & 0x55555555;
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = ((n >> 4) + n) & 0x0F0F0F0F;
    n += n >> 8;
    n += n >> 16;
    return n & 0x0000003F;
}

int main(void)
{
    uint32_t a = 0x5A5A5A5AU;
    uint32_t b = 0xA5A5A5A5U;
    uint32_t c = 0U;
    uint32_t d = 0xFFFFFFFFU;

    printf("bits in a: %d\n", hacker_popcnt(a));
    printf("bits in b: %d\n", hacker_popcnt(b));
    printf("bits in c: %d\n", hacker_popcnt(c));
    printf("bits in d: %d\n", hacker_popcnt(d));

    return 0;
}

