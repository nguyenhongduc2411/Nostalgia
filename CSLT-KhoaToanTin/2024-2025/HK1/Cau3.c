#include <stdio.h>

/*

idx
Dòng: idx / COLS (Làm tròn xuống)
Cột: idx % COLS

Dãy 9 3 11 có chiều dài là 3 thì có bao nhiêu dãy con trong đây
n * (n + 1) / 2
Dãy 1 số: 1 * (1 + 1) / 2 = 1
Dãy 2 số: 2 * (2 + 1) / 2 = 3
Dãy 3 số: 3 * (3 + 1) / 2 = 6

i = 0: Bắt cặp với j = 0, j = 1, j = 2
i = 1: Bắt cặp với j = 1, j = 2
i = 2: Bắt cặp với j = 2

Tổng các số từ 1..n = n * (n + 1) / 2

2 1 4 0 0 5
1 6 2 3 7 0
5 1 0 7 8 9
3 11 0 6 9 2

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

*/

#define ROWS 4
#define COLS 6

int main()
{
    int matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    const int SIZE = ROWS * COLS; // Số phần tử
    int idx = 0;
    int totalSubarrays = 0;
    int maxLen = 0;
    int bestStart = -1;

    while (idx < SIZE) {
        int row = idx / COLS;
        int col = idx % COLS;

        // Tìm được chiều dài của dãy các số lẻ liên tiếp
        int len = 0;
        int start = idx;
        while (idx < SIZE && matrix[row][col] % 2 != 0) {
            idx++;
            len++;
            row = idx / COLS;
            col = idx % COLS;
        }

        totalSubarrays += len * (len + 1) / 2;
        if (len > maxLen) {
            maxLen = len;
            bestStart = start;
        }

        idx++;
    }

    printf("%d\n", totalSubarrays);
    printf("%d\n", maxLen);

    if (maxLen > 0) {
        for (int idx = bestStart, cnt = 0; cnt < maxLen; idx++, cnt++) {
            int row = idx / COLS;
            int col = idx % COLS;
            printf("%d\t%d\n", row, col);
        }
    }

    return 0;
}