#include <iostream>
using namespace std;

const int MAX = 100;
int decipher(int B[][MAX], int nRow, int nCol, int A[], int k)
{
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j + k - 1 < nCol; j++) {
            bool found = true;
            
            for (int idx = 0; idx < k; idx++) {
                if (A[idx] != B[i][j + idx]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                int sum = 0;

                for (int idx = j - 1; idx >= 0; idx--) {
                    sum += B[i][idx];
                }

                for (int idx = j + k; idx < nCol; idx++) {
                    sum += B[i][idx];
                }

                return sum;
            }
        }
    }

    return 0;
}

int countAtPos(int B[][MAX], int nRow, int nCol, int A[], int k, int i, int j) {
    int cnt = 0;

    for (int idx = 0; idx < k; idx++) {
        if (B[i][j + idx] != A[idx])
            break;

        if (idx == k - 1)
            cnt++;

        if (k == 1)
            return cnt;
    }

    for (int idx = 0; idx < k; idx++) {
        if (B[i][j - idx] != A[idx])
            break;

        if (idx == k - 1)
            cnt++;
    }

    for (int idx = 0; idx < k; idx++) {
        if (B[i + idx][j] != A[idx])
            break;

        if (idx == k - 1)
            cnt++;
    }

    for (int idx = 0; idx < k; idx++) {
        if (B[i - idx][j] != A[idx])
            break;

        if (idx == k - 1)
            cnt++;
    }

    return cnt;
}

int countAppearances(int B[][MAX], int nRow, int nCol, int A[], int k)
{
    int cnt = 0;

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            cnt += countAtPos(B, nRow, nCol, A, k, i, j);
        }
    }

    return cnt;
}

int main()
{
    // int B[][MAX] = {
    //     {1, 12, 33, 3, 5},
    //     {2, 44, 51, 94, 83},
    //     {4, 5, 6, 7, 8},
    //     {4, 5, 5, 5, 8}
    // };
    // int A[] = {6, 7};

    // cout << decipher(B, 4, 5, A, 2);

    int B[][MAX] = {
        {3, 2, 1, 2, 3, 1},
        {3, 2, 1, 3, 2, 1},
        {2, 0, 2, 1, 7, 9},
        {1, 2, 3, 2, 1, 6}
    };
    int A[] = {1};

    cout << countAppearances(B, 4, 6, A, 1);

    return 0;
}