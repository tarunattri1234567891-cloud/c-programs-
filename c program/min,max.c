#include <stdio.h>

int main()
{
    int a[10][10], r, c, i, j;
    int min, max;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    if (r < 1 || r > 10 || c < 1 || c > 10)
    {
        printf("Invalid matrix size.");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    min = max = a[0][0];

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] < min)
                min = a[i][j];

            if (a[i][j] > max)
                max = a[i][j];
        }
    }

    printf("Minimum element = %d\n", min);
    printf("Maximum element = %d\n", max);

    return 0;
}