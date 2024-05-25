#include <stdio.h>

const int MAX = 100;

int hasNegativeOnAllRows(int matrix[MAX][MAX], int m, int n)
{
    for (int i = 0; i < m; i++) {
        int hasNegative = 0;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                hasNegative = 1;
                break;
            }
        }

        if (!hasNegative)
            return 0;
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

    printf("%d", hasNegativeOnAllRows(matrix, m, n));

    return 0;
}