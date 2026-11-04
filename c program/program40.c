#include <stdio.h>

#define MAX 10

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int i, j, k;
    int r1, c1, r2, c2;
    int choice;

    do
    {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Addition of Matrices\n");
        printf("2. Subtraction of Matrices\n");
        printf("3. Upper and Lower Triangular Matrix\n");
        printf("4. Transpose of Matrix\n");
        printf("5. Product of Matrices\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter elements of Matrix A:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &A[i][j]);

                printf("Enter elements of Matrix B:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &B[i][j]);

                printf("Addition Result:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        C[i][j] = A[i][j] + B[i][j];
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                printf("Enter rows and columns: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter Matrix A:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &A[i][j]);

                printf("Enter Matrix B:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &B[i][j]);

                printf("Subtraction Result:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c1; j++)
                    {
                        C[i][j] = A[i][j] - B[i][j];
                        printf("%d ", C[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                printf("Enter order of square matrix: ");
                scanf("%d", &r1);

                printf("Enter matrix elements:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < r1; j++)
                        scanf("%d", &A[i][j]);

                printf("Upper Triangular Matrix:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < r1; j++)
                    {
                        if (i <= j)
                            printf("%d ", A[i][j]);
                        else
                            printf("0 ");
                    }
                    printf("\n");
                }

                printf("Lower Triangular Matrix:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < r1; j++)
                    {
                        if (i >= j)
                            printf("%d ", A[i][j]);
                        else
                            printf("0 ");
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Enter rows and columns: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter matrix elements:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &A[i][j]);

                printf("Transpose Matrix:\n");
                for (i = 0; i < c1; i++)
                {
                    for (j = 0; j < r1; j++)
                        printf("%d ", A[j][i]);

                    printf("\n");
                }
                break;

            case 5:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if (c1 != r2)
                {
                    printf("Matrix multiplication not possible.\n");
                    break;
                }

                printf("Enter Matrix A:\n");
                for (i = 0; i < r1; i++)
                    for (j = 0; j < c1; j++)
                        scanf("%d", &A[i][j]);

                printf("Enter Matrix B:\n");
                for (i = 0; i < r2; i++)
                    for (j = 0; j < c2; j++)
                        scanf("%d", &B[i][j]);

                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c2; j++)
                    {
                        C[i][j] = 0;

                        for (k = 0; k < c1; k++)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }

                printf("Product of Matrices:\n");
                for (i = 0; i < r1; i++)
                {
                    for (j = 0; j < c2; j++)
                        printf("%d ", C[i][j]);

                    printf("\n");
                }
                break;

            case 0:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}