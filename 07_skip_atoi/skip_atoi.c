#include <stdio.h>

/******************************************************************************
* This piece of code is copied from linux kernal and change some code format.
*/
#define is_digit(c)	((c) >= '0' && (c) <= '9')

int skip_atoi(const char **s)
{
    int i = 0;

    /**************************************************************************
    /* If find a number, then you need to do the corresponding processing: */
    /* the pointer points to the next location, minus the '0' to directly */
    /* determine the value represented by this character. About the change */
    /* of i, I spend a long time before I figured it out. In fact, this is */
    /* to support the judgment of numbers exceeding 10, and this has a */
    /* premise that when the CPU recognizes the memory, it must process */
    /* the memory information according to the little endian or the memory */
    /* should be processed as an array. */
    while (is_digit(**s))
    {
        i = i * 10 + *((*s)++) - '0';
    }

    return i;
}

char c[] = "234";
char c1 = '7';
const char *p_c;
const char **p_p_c;

int main(void)
{
    p_c = &c1;
    p_p_c = &p_c;
    printf("result: %d\n", skip_atoi(p_p_c));

    p_c = c;
    p_p_c = &p_c;
    printf("result: %d\n", skip_atoi(p_p_c));

    return 0;
}

