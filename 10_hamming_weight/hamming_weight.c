#include <stdint.h>
#include <stdio.h>

uint32_t hamming_weight(uint32_t n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

    return n;
}


int main(void)
{
    printf("hamming weight of 0xFFFFFFFFU is: %d\n", hamming_weight(0xFFFFFFFFU));
    printf("hamming weight of 0x5A5A5A5AU is: %d\n", hamming_weight(0x5A5A5A5AU));
    printf("hamming weight of 0xA5A5A5A5U is: %d\n", hamming_weight(0xA5A5A5A5U));
    printf("hamming weight of 0x0U is: %d\n", hamming_weight(0x0U));
    printf("hamming weight of 0b10000000U is: %d\n", hamming_weight(0b10000000U));
    printf("hamming weight of 0b1U is: %d\n", hamming_weight(0b1U));
    printf("hamming weight of 12345 is: %d\n", hamming_weight(12345));

    return 0;
}
