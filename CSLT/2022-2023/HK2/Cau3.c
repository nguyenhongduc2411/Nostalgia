#include <stdio.h>

void printGradeFrequencies(int grades[], int n)
{
    int freq[11] = {}; // 0 - 10

    for (int i = 0; i < n; i++) {
        freq[grades[i]]++;
    }

    for (int i = 0; i <= 10; i++) {
        printf("Diem %d xuat hien %d lan\n", i, freq[i]);
    }
}

int main()
{
    int grades[] = {0, 1, 2, 2, 4, 3, 2, 7, 8, 9, 10};
    int n = sizeof(grades) / sizeof(*grades);

    printGradeFrequencies(grades, n);

    return 0;
}