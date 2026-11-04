#include <stdio.h>

int main()
{
    int arr[100], n, i, sum = 0;
    int *ptr;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter array elements: ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    for(i = 0; i < n; i++)
    {
        sum = sum + *ptr;
        ptr++;
    }

    printf("Sum of array elements = %d", sum);

    return 0;
}