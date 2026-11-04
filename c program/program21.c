#include <stdio.h>

int main()
{
    int a[100], temp[100];
    int n, pos, i, k = 0;

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

    printf("Enter split position (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid split position.");
        return 0;
    }

    for (i = 0; i < pos - 1; i++)
    {
        temp[k] = a[i];
        k++;
    }

    for (i = 0; i < n - (pos - 1); i++)
    {
        a[i] = a[i + pos - 1];
    }

    for (i = 0; i < pos - 1; i++)
    {
        a[n - (pos - 1) + i] = temp[i];
    }

    printf("Array after splitting and rotating:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}