#include "stdint.h"
#include "stdio.h"

uint8_t hexchar2num(char c)
{
    if ((c >= 'a') && (c <= 'f'))
    {
        c -= 32;
    }

    if (c >= 'A')
    {
        return (c - 'A' + 10);
    }
    else
    {
        return (c - '0');
    }
}

uint8_t hexc2har2num(char *p_s)
{
    return ((hexchar2num(p_s[0]) << 4) + hexchar2num(p_s[1]));
}

// some test

char s1[] = "0123456789ABCDEF";
char s2[] = "0123456789abcdef";


int main(void)
{
    int i = 0;
 
    for (i = 0; i < sizeof(s1) - 1; i++)
    {
        printf("%d,", hexchar2num(s1[i]));
    }
 
    printf("\n");
 
    for (i = 0; i < sizeof(s2) - 1; i++)
    {
        printf("%d,", hexchar2num(s2[i]));
    }
 
    printf("\n");
 
    for (i = 0; i < (sizeof(s1) - 1) / 2; i++)
    {
        printf("%0d,", hexc2har2num(&s1[2 * i]));
    }
 
    printf("\n");
 
    for (i = 0; i < (sizeof(s1) - 1) / 2; i++)
    {
        printf("%02x,", hexc2har2num(&s1[2 * i]));
    }
 
    return 0;
}

