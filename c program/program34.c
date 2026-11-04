#include <stdio.h>

int main()
{
    char str[100];
    char *ptr;
    int count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    ptr = str;

    while(*ptr != '\0' && *ptr != '\n')
    {
        count++;
        ptr++;
    }

    printf("Length of string = %d", count);

    return 0;
}