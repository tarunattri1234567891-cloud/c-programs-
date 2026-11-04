#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[50];
    char *pos;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Enter the word to search: ");
    scanf("%49s", word);

    pos = strstr(str, word);

    if (pos != NULL)
    {
        printf("Word found at position: %ld",
               (long)(pos - str + 1));
    }
    else
    {
        printf("Word not found.");
    }

    return 0;
}
