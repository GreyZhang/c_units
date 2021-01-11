/* #include <ctype.h> */
#include <stdio.h>

/* we use this so that we can do without the ctype library */
#define is_digit(c)	((c) >= '0' && (c) <= '9')

int main(void)
{
    printf("%d\n", is_digit(1));
    printf("%d\n", is_digit(2));
    printf("%d\n", is_digit(3));
    printf("%d\n", is_digit(4));
    printf("%d\n", is_digit('1'));
    printf("%d\n", is_digit('2'));
    printf("%d\n", is_digit('3'));
    printf("%d\n", is_digit('4'));
    printf("%d\n", is_digit('a'));
    printf("%d\n", is_digit('b'));
    printf("%d\n", is_digit('c'));
    printf("%d\n", is_digit('d'));

    return 0;
}

