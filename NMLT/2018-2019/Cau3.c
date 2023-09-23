#include <stdio.h>
#define N 3
#define N_NUMBERS N * N

/*
    Note: Có thể làm thêm khúc nhập N từ bàn phím
          và kích thước khởi tạo thì khai báo là 1 SIZE nào đó đủ lớn, ví dụ SIZE = 100
*/

void inputMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void outputMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isMagicSquare(int matrix[N][N])
{
    // Check distinct numbers
    int arr[N_NUMBERS];
    int currentIdx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[currentIdx] = matrix[i][j];
            currentIdx++;
        }
    }
    for (int i = 0; i < N_NUMBERS - 1; i++) {
        for (int j = i + 1; j < N_NUMBERS; j++) {
            if (arr[i] == arr[j])
                return 0;
        }
    }

    int magicSum = 0;
    for (int j = 0; j < N; j++) {
        magicSum += matrix[0][j];
    }

    // Check rows
    for (int i = 1; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
        if (sum != magicSum)
            return 0;
    }

    // Check cols
    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += matrix[i][j];
        }
        if (sum != magicSum)
            return 0;
    }

    // Check top-left - bottom-right diagonal
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][i];
    }
    if (sum != magicSum)
        return 0;

    // Check top-right - bottom-left diagonal
    sum = 0;
    for (int i = 0; i < N; i++) {
        sum += matrix[i][N - i - 1];
    }
    if (sum != magicSum)
        return 0;

    return 1;
}

/*

2 7 6
9 5 1
4 3 8

1 2 3
4 5 6
7 8 9

2 7 6
9 5 1
4 3 10

*/

int main()
{
    int matrix[N][N];
    inputMatrix(matrix);
    // outputMatrix(matrix);
    printf("isMagicSquare: %d", isMagicSquare(matrix));
    return 0;
}