#include <stdio.h>
#include <string.h>

struct Employee
{
    char id[10];
    char name[50];
    char gender[5];
    double salary;
};

void readEmployees(Employee employees[], int &size)
{
    size = 0;

    FILE* pFile = fopen("INPUT.TXT", "r");
    if (pFile == NULL)
        return;

    const int MAX = 100;
    char line[MAX];
    while (fgets(line, MAX, pFile) != NULL) {
        Employee e;
        sscanf(line, "%[^-]-%[^-]-%[^-]-%lf", e.id, e.name, e.gender, &e.salary);

        employees[size] = e;
        size++;
    }

    fclose(pFile);
}

void writeEmployess(Employee employees[], int size)
{
    FILE* pFile = fopen("OUTPUT.TXT", "w");
    if (pFile == NULL)
        return;

    int maxNameLength = 0;
    double maxSalary = 0;

    for (int i = 0; i < size; i++) {
        Employee e = employees[i];

        int nameLength = strlen(e.name);
        if (nameLength > maxNameLength)
            maxNameLength = nameLength;

        if (e.salary > maxSalary)
            maxSalary = e.salary;
    }

    bool found = false;
    for (int i = 0; i < size; i++) {
        Employee e = employees[i];

        if (strlen(e.name) == maxNameLength && e.salary == maxSalary) {
            fprintf(pFile, "%s-%s-%s-%.1lf\n", e.id, e.name, e.gender, e.salary);
            found = true;
        }
    }

    if (!found)
        fputs("khong ton tai", pFile);

    fclose(pFile);
}

int main()
{
    const int MAX = 100;
    Employee employees[MAX];
    int size;

    readEmployees(employees, size);
    writeEmployess(employees, size);

    return 0;
}