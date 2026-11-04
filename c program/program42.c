#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
    char designation;
};

int main()
{
    struct Employee emp[100];
    FILE *managerFile, *workerFile;
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of employees.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%49s", emp[i].name);

        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);

        printf("Enter Designation (M for Manager, W for Worker): ");
        scanf(" %c", &emp[i].designation);
    }

    managerFile = fopen("managers.txt", "w");
    workerFile = fopen("workers.txt", "w");

    if (managerFile == NULL || workerFile == NULL)
    {
        printf("Error opening files.\n");

        if (managerFile != NULL)
            fclose(managerFile);

        if (workerFile != NULL)
            fclose(workerFile);

        return 1;
    }

    for (i = 0; i < n; i++)
    {
        if (emp[i].designation == 'M' ||
            emp[i].designation == 'm')
        {
            fprintf(managerFile,
                    "ID: %d, Name: %s, Salary: %.2f\n",
                    emp[i].id,
                    emp[i].name,
                    emp[i].salary);
        }
        else if (emp[i].designation == 'W' ||
                 emp[i].designation == 'w')
        {
            fprintf(workerFile,
                    "ID: %d, Name: %s, Salary: %.2f\n",
                    emp[i].id,
                    emp[i].name,
                    emp[i].salary);
        }
    }

    fclose(managerFile);
    fclose(workerFile);

    printf("\nEmployee records stored successfully.\n");
    printf("Managers data saved in managers.txt\n");
    printf("Workers data saved in workers.txt\n");

    return 0;
}