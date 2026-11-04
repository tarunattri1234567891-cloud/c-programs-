#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;

    printf("Enter first number: ");
    scanf("%d", &x);

    printf("Enter second number: ");
    scanf("%d", &y);

    printf("\nBefore swapping:");
    printf("\nFirst number = %d", x);
    printf("\nSecond number = %d", y);

    swap(&x, &y);

    printf("\n\nAfter swapping:");
    printf("\nFirst number = %d", x);
    printf("\nSecond number = %d", y);

    return 0;
}