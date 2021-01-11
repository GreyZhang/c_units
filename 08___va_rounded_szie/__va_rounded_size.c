#include <stdio.h>

/*
The following is actually an algorithm for rounding up, calculating how many
int spaces are needed to accommodate TYPE.
*/
#define __va_rounded_size(TYPE)  \
  (((sizeof (TYPE) + sizeof (int) - 1) / sizeof (int)) * sizeof (int))

const char *fmt;
char char_var;
int int_var;
float float_var;
double double_var;

char *p_char_var;
int *p_int_var;
float *p_float_var;
double *p_double_var;

int main(void)
{
    printf("result for fmt: %d\n", __va_rounded_size(fmt));
    printf("result for char_var: %d\n", __va_rounded_size(char_var));
    printf("result for int_var: %d\n", __va_rounded_size(int_var));
    printf("result for float_var: %d\n", __va_rounded_size(float_var));
    printf("result for double_var: %d\n", __va_rounded_size(double_var));

    printf("result for p_char_var: %d\n", __va_rounded_size(p_char_var));
    printf("result for p_int_var: %d\n", __va_rounded_size(p_int_var));
    printf("result for p_float_var: %d\n", __va_rounded_size(p_float_var));
    printf("result for p_double_var: %d\n", __va_rounded_size(p_double_var));

    return 0;
}

