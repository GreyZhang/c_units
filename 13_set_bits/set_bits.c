/* both clear and set function are supported, set with 0 means clear */
void set_u32_bit(uint32_t *p_raw, uint8_t pos, uint8_t val)
{
    if (val == 0U)
    {
        /* should clear bit */
        *p_raw &= ~(1U << pos);
    }
    else
    {
        /* should set bit */
        *p_raw |= (1U << pos);
    }
}
