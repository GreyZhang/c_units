#include <stdio.h>

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(void)
{
    int i = 0;

    for(i = 0; i < 128; i++)
    {
        printf("%d,", map(i, 0, 127, 0, 5000));

        if((i % 20 == 0) && (i != 0))
        {
            printf("\n");
        }
    }

    return 0;
}

