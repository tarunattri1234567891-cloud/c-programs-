#include <stdio.h>

// Function to check subset
int isSubset(int A[], int B[], int n, int m)
{
    int i, j, found;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < m; j++)
        {
            if(A[i] == B[j])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int A[100], B[100];
    int n, m, i;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter elements of first array:\n ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &m);

    printf("Enter elements of second array:\n ");

    for(i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    if(isSubset(A, B, n, m))
    {
        printf("First array is a subset of second array.");
    }
    else
    {
        printf("First array is not a subset of second array.");
    }

    return 0;
}