#include <stdio.h>

int main()
{
    int n, i, j, num = 1;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    if (n < 1 || n > 50)
    {
        printf("Invalid number of rows.");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d ", num);
            num++;
        }

        printf("\n");
    }

    return 0;
}