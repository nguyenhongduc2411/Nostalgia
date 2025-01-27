#include <stdio.h>

#define MAX 100

int coDoiXungTam(int matrix[MAX][MAX], int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[m - i - 1][n - j - 1])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int matrix[MAX][MAX];

    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("%d", coDoiXungTam(matrix, m, n));

    return 0;
}