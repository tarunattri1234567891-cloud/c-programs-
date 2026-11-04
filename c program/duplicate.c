#include <stdio.h>

int main()
{
    int a[100], n, i, j, count = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid array size.");
        return 0;
    }

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] == -1)
            continue;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                a[j] = -1;
                count++;
            }
        }
    }

    printf("Total duplicate occurrences = %d\n", count);

    printf("Updated array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}