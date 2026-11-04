#include <stdio.h>

// Function to check perfect number
int isPerfect(int n)
{
    int i, sum = 0;

    for(i = 1; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            sum = sum + i;
        }
    }

    if(sum == n && n > 0)
        return 1;
    else
        return 0;
}

// Function to print perfect numbers
void printPerfect(int start, int end)
{
    int i;

    printf("Perfect numbers are: ");

    for(i = start; i <= end; i++)
    {
        if(isPerfect(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int start, end;

    printf("Enter starting interval: ");
    scanf("%d", &start);

    printf("Enter ending interval: ");
    scanf("%d", &end);

    printPerfect(start, end);

    return 0;
}