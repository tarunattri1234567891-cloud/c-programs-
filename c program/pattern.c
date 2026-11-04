#include <stdio.h>

int main() {
    int choice, n, i, j;

    printf("1. Star pattern\n");
    printf("2. Number pattern\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter number of rows: ");
    scanf("%d", &n);

    switch (choice) {
        case 1:
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 2:
            for (i = 1; i <= n; i++) {
                // leading spaces
                for (j = 1; j <= n - i; j++) {
                    printf("  ");
                }
                // increasing part: 1 to i
                for (j = 1; j <= i; j++) {
                    printf("%d ", j);
                }
                // decreasing part: i-1 to 1
                for (j = i - 1; j >= 1; j--) {
                    printf("%d ", j);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}