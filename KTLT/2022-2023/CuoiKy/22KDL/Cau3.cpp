#include <stdio.h>
#include <string.h>

const char* STUDENTS_FILE = "students.txt";

struct Subject
{
    char name[20];
    double grade;
};

struct Student
{
    char id[20];
    int nSubjects;
    Subject subjects[20];
};

void loadStudents(Student students[], int& n)
{
    n = 0;

    FILE* pFile = fopen(STUDENTS_FILE, "rt");
    if (pFile == NULL) {
        return;
    }

    fscanf(pFile, "%d%*c", &n);

    for (int i = 0; i < n; i++) {
        Student& student = students[i];
        fscanf(pFile, "%[^,]%*c", student.id);
        fscanf(pFile, "%d%*c", &student.nSubjects);

        for (int j = 0; j < student.nSubjects; j++) {
            Subject& subject = student.subjects[j];
            fscanf(pFile, "%[^,]%*c", subject.name);
            fscanf(pFile, "%lf%*c", &subject.grade);
        }
    }

    fclose(pFile);
}

void scanNewStudent(Student students[], int& n)
{
    Student& student = students[n];

    printf("MSSV: ");
    scanf("%[^\n]", student.id);

    printf("So mon hoc: ");
    scanf("%d%*c", &student.nSubjects);

    for (int i = 0; i < student.nSubjects; i++) {
        Subject& subject = student.subjects[i];

        printf("Ten mon hoc: ");
        scanf("%[^\n]", subject.name);

        printf("Diem mon hoc: ");
        scanf("%lf%*c", &subject.grade);
    }

    n++;
}

void scanNewStudents(Student students[], int& n)
{
    int nNewStudents;
    printf("Nhap so sinh vien can them moi: ");
    scanf("%d%*c", &nNewStudents);
    for (int i = 0; i < nNewStudents; i++) {
        scanNewStudent(students, n);
    }
}

void saveStudents(const Student students[], int n)
{
    FILE* pFile = fopen(STUDENTS_FILE, "wt");
    if (pFile == NULL) {
        printf("Error opening file %s for saving", STUDENTS_FILE);
        return;
    }

    fprintf(pFile, "%d\n", n);

    for (int i = 0; i < n; i++) {
        const Student& student = students[i];
        fprintf(pFile, "%s,%d,", student.id, student.nSubjects);

        for (int j = 0; j < student.nSubjects; j++) {
            const Subject& subject = student.subjects[j];
            fprintf(pFile, "%s,%lf", subject.name, subject.grade);
            if (j + 1 < student.nSubjects)
                fprintf(pFile, ",");
        }

        if (i + 1 < n)
            fprintf(pFile, "\n");
    }

    fclose(pFile);
}

void printSubjects(const Student students[], int n, const char* id)
{
    for (int i = 0; i < n; i++) {
        const Student& student = students[i];
        if (strcmp(student.id, id) == 0) {
            printf("Bang diem cua sinh vien %s:\n", id);
            for (int j = 0; j < student.nSubjects; j++) {
                const Subject& subject = student.subjects[j];
                printf("%s: %lf\n", subject.name, subject.grade);
            }
        }
    }
}

double getGPA(const Student& student)
{
    if (student.nSubjects <= 0)
        return 0;

    double gpa = 0;
    for (int i = 0; i < student.nSubjects; i++) {
        gpa += student.subjects[i].grade;
    }
    return gpa / student.nSubjects;
}

void sortStudents(Student students[], int n)
{
    // So sánh theo GPA giảm dần
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (getGPA(students[i]) < getGPA(students[j])) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printScholarshipStudents(Student students[], int n)
{
    sortStudents(students, n);

    printf("Danh sach sinh vien duoc hoc bong:\n");
    double maxAmount = n * 0.3;

    for (int i = 0; i < n && i + 1 < maxAmount; i++) {
        if (getGPA(students[i]) > 7.5)
            printf("%s: %lf\n", students[i].id, getGPA(students[i]));
        else
            break;
    }
}

int main()
{
    Student students[100];
    int n;

    loadStudents(students, n);
    scanNewStudents(students, n);
    saveStudents(students, n);

    printSubjects(students, n, "222");
    printScholarshipStudents(students, n);

    return 0;
}