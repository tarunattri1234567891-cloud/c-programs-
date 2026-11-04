#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, j, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    i = 0;
    j = strlen(str) - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            flag = 0;
            break;
        }

        i++;
        j--;
    }

    if (flag == 1)
    {
        printf("The string is a Palindrome.");
    }
    else
    {
        printf("The string is not a Palindrome.");
    }

    return 0;
}