#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

const int MAXCOL = 100;

void findSpecialPoints(int mat[][MAXCOL], int nRow, int nCol,
                        int& xA, int& yA, int& xB, int& yB) {
    xA = -1;
    yA = -1;

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (isPrime(mat[i][j])) {
                if (xA == -1 || mat[i][j] > mat[xA][yA]) {
                    xA = i;
                    yA = j;
                }
            }
        }
    }

    xB = -1;
    yB = -1;

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (i == xA && j == yA)
                continue;

            if (isPrime(mat[i][j])) {
                if (xB == -1 || mat[i][j] > mat[xB][yB]) {
                    xB = i;
                    yB = j;
                }
            }
        }
    }
}

bool checkCountPrime(int mat[][MAXCOL], int nRow, int nCol,
                    int xA, int yA, int xB, int yB,
                    int i, int j, int& cntPrime) {
    if ((xA == i && yA == j) || (xB == i && yB == j)) {
        if (cntPrime < 0) {
            cntPrime = 0;
            return false;
        }

        return true;
    }

    if (cntPrime >= 0 && isPrime(mat[i][j])) {
        cntPrime++;
    }

    return false;
}

int countPrimeFromTwoPoints(int mat[][MAXCOL], int nRow, int nCol,
                            int xA, int yA, int xB, int yB) {
    if (nRow <= 0 || nCol <= 0)
        return 0;

    if (xA < 0 || xA >= nRow || yA < 0 || yA >= nCol)
        return 0;

    if (xB < 0 || xB >= nRow || yB < 0 || yB >= nCol)
        return 0;

    if (xA == xB && yA == yB)
        return 0;

    int cntPrime = -1;
    int cnt = 0;
    int direction = 0; // 0 1 2 3
    int startRow = 0, startCol = 0;
    bool done = false;

    while (cnt < nRow * nCol) {
        if (direction == 0) {
            int i = startRow;
            for (int j = startCol; j <= nCol - startCol - 1; j++) {
                // cout << mat[i][j] << " ";
                cnt++;
                done = checkCountPrime(mat, nRow, nCol, xA, yA, xB, yB, i, j, cntPrime);
                if (done)
                    return cntPrime;
            }
        }
        else if (direction == 1) {
            int j = nCol - startCol - 1;
            for (int i = startRow + 1; i <= nRow - startRow - 1; i++) {
                // cout << mat[i][j] << " ";
                cnt++;
                done = checkCountPrime(mat, nRow, nCol, xA, yA, xB, yB, i, j, cntPrime);
                if (done)
                    return cntPrime;
            }
        }
        else if (direction == 2) {
            int i = nRow - startRow - 1;
            for (int j = nCol - startCol - 2; j >= startCol; j--) {
                // cout << mat[i][j] << " ";
                cnt++;
                done = checkCountPrime(mat, nRow, nCol, xA, yA, xB, yB, i, j, cntPrime);
                if (done)
                    return cntPrime;
            }
        }
        else if (direction == 3) {
            int j = startCol;
            for (int i = nRow - startRow - 2; i >= startRow + 1; i--) {
                // cout << mat[i][j] << " ";
                cnt++;
                done = checkCountPrime(mat, nRow, nCol, xA, yA, xB, yB, i, j, cntPrime);
                if (done)
                    return cntPrime;
            }
        }

        direction = (direction + 1) % 4;
        if (direction == 0) {
            startRow++;
            startCol++;
        }
    }

    return cntPrime;
}

int main()
{
    // int mat[][MAXCOL] = {
    //     {1, 2, 3, 4},
    //     {12, 13, 14, 5},
    //     {11, 16, 15, 6},
    //     {10, 9, 8, 7}
    // };

    // int xA, yA, xB, yB;
    // findSpecialPoints(mat, 4, 4, xA, yA, xB, yB);
    // cout << "xA = " << xA << ", yA = " << yA << ", xB = " << xB << ", yB = " << yB << "\n";

    // int mat[][MAXCOL] = {
    //     {9, 21, 36, 44},
    //     {7, 5, 14, 52},
    //     {20, 11, 17, 88},
    //     {13, 9, 8, 25}
    // };

    int mat[][MAXCOL] = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };

    int xA = 0, yA = 0;
    int xB = 2, yB = 1;
    cout << "countPrime: " << countPrimeFromTwoPoints(mat, 4, 4, xB, yB, xA, yA) << "\n";

    return 0;
}