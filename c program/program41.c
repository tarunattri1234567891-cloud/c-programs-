#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *source, *destination;
    int ch;

    if (argc != 3)
    {
        printf("Usage: %s source.txt destination.txt\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "r");

    if (source == NULL)
    {
        printf("Error opening source file.\n");
        return 1;
    }

    destination = fopen(argv[2], "w");

    if (destination == NULL)
    {
        printf("Error opening destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}