#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

int main()
{
    FILE *fp;
    struct Student s;
    int n, i, search, found = 0;

    // Store student records
    fp = fopen("Student.txt", "wb");

    if(fp == NULL)
    {
        printf("File cannot be opened.");
        return 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter roll, name and marks: ");
        scanf("%d %49s %f",
              &s.roll, s.name, &s.marks);

        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);

    // Read student records
    fp = fopen("Student.txt", "rb");

    printf("\nStudent Records:\n");

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%d %s %.2f\n",
               s.roll, s.name, s.marks);
    }

    fclose(fp);

    // Edit student record
    fp = fopen("Student.txt", "rb+");

    printf("Enter roll number to edit: ");
    scanf("%d", &search);

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.roll == search)
        {
            printf("Enter new name and marks: ");
            scanf("%49s %f", s.name, &s.marks);

            fseek(fp, -(long)sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("Record not found.\n");

    fclose(fp);

    // Append a new student record
    fp = fopen("Student.txt", "ab");

    printf("\nEnter new student details: ");
    scanf("%d %49s %f",
          &s.roll, s.name, &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("Record appended successfully.");

    return 0;
}