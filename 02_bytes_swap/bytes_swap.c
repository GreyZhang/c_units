#include <stdint.h>
#include <stdio.h>

typedef enum
{
    BYTES_SWAP_ERR_OK = 0,
    BYTES_SWAP_ERR_BYTES_NUM
} bytes_swap_error_t;

void byte_value_swap(uint8_t *p_a, uint8_t *p_b)
{
    /* 8 bit swap. swap drectly */
    *p_a = *p_a ^ *p_b;
    *p_b = *p_a ^ *p_b;
    *p_a = *p_a ^ *p_b;
}

bytes_swap_error_t bytes_swap(void *p_v, uint8_t n)
{
    bytes_swap_error_t r;

    switch (n)
    {
    case 2:
        byte_value_swap((uint8_t *)p_v, (uint8_t *)p_v + 1);
        break;
    case 4:
        byte_value_swap((uint8_t *)p_v, (uint8_t *)p_v + 3);
        byte_value_swap((uint8_t *)p_v + 1, (uint8_t *)p_v + 2);
        break;
    case 8:
        byte_value_swap((uint8_t *)p_v + 0, (uint8_t *)p_v + 7);
        byte_value_swap((uint8_t *)p_v + 1, (uint8_t *)p_v + 6);
        byte_value_swap((uint8_t *)p_v + 2, (uint8_t *)p_v + 5);
        byte_value_swap((uint8_t *)p_v + 3, (uint8_t *)p_v + 4);
        break;
    default:
        r = BYTES_SWAP_ERR_BYTES_NUM;
        break;
    }

    return r;
}

int main(void)
{
    uint8_t a = 0x12U;
    uint8_t b = 0x34U;
    uint16_t c = 0xABCDU;
    uint32_t d = 0x12345678U;
    uint64_t e = 0xA1B2C3D4E5F67788ULL;

    printf("a = 0x%x, b = 0x%x\n", a, b);
    printf("after swap:\n");
    byte_value_swap(&a, &b);
    printf("a = 0x%x, b = 0x%x\n\n", a, b);

    printf("c = 0x%x\n", c);
    printf("after swap:\n");
    bytes_swap(&c, 2);
    printf("c = 0x%x\n\n", c);

    printf("d = %0x\n", d);
    printf("after swap:\n");
    bytes_swap(&d, 4);
    printf("d = %0x\n\n", d);

    printf("e = 0x%016I64x\n", e);
    printf("after swap:\n");
    bytes_swap(&e, 8);
    printf("e = 0x%016I64x\n\n", e);

    return 0;
}
