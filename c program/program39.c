#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat file;

    char filename[100];

    printf("Enter filename: ");
    scanf("%99s", filename);

    if(stat(filename, &file) == 0)
    {
        printf("\nFile Properties:\n");

        printf("File size = %ld bytes\n",
               (long)file.st_size);

        printf("Last modified time = %s",
               ctime(&file.st_mtime));

        printf("File permissions = %o\n",
               (unsigned int)(file.st_mode & 0777));
    }
    else
    {
        printf("File does not exist.");
    }

    return 0;
}