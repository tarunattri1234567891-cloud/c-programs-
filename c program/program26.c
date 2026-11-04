#include <stdio.h>

int main()
{
    int i, j;

    for (i = 1; i <= 8; i++)
    {
        for (j = 1; j <= 8 - i; j++)
            printf(" ");

        for (j = 1; j <= 8; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}