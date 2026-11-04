#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;

    int lower = 0;
    int upper = 0;
    int digit = 0;
    int special = 0;

    fp = fopen("data.txt", "r");

    if(fp == NULL)
    {
        printf("File not found.");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch >= 'a' && ch <= 'z')
            lower++;

        else if(ch >= 'A' && ch <= 'Z')
            upper++;

        else if(ch >= '0' && ch <= '9')
            digit++;

        else if(ch != ' ' && ch != '\n' && ch != '\t')
            special++;
    }

    fclose(fp);

    printf("Lowercase letters = %d\n", lower);
    printf("Uppercase letters = %d\n", upper);
    printf("Numbers = %d\n", digit);
    printf("Special characters = %d\n", special);

    return 0;
}