#include <stdio.h>

/*

Tính ra tổng các phần tử trên từng hàng
Tính ra tổng các phần tử trên từng cột
Duyệt qua mảng B để mình kiểm tra 
tổng các phần tử trên từng hàng >= tổng các phần tử trên từng cột

*/

void taoMaTranB(int A[100][100], int B[100][100], int m, int n)
{
    int sumRows[100] = {0};
    int sumCols[100] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sumRows[i] += A[i][j];
            sumCols[j] += A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (sumRows[i] >= sumCols[j])
                B[i][j] = 1;
            else
                B[i][j] = 0;
        }
    }
}

int tongMang(int a[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int A[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int B[100][100];
    taoMaTranB(A, B, m, n);

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", B[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < m; i++) {
        printf("%d\n", tongMang(B[i], n));
    }

    return 0;
}