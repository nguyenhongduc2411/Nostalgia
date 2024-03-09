#include <iostream>
using namespace std;

// Chạy tay -> Nó sẽ in ra cái gì -> Nếu khớp thì đúng

int **createMatrix(int m, int a, int b, int c)
{
    int** matrix = new int*[m];
    int signRow = -1;

    for (int i = 0; i < m; i++) {
        int currentSize = 0;

        if (i % 3 == 0) {
            currentSize = a;
        }
        else if (i % 3 == 1) {
            currentSize = b;
        }
        else {
            currentSize = c;
        }

        int sign = signRow;
        matrix[i] = new int[currentSize];
        for (int j = 0, currentElement = currentSize; j < currentSize; j++, currentElement--) {
            matrix[i][j] = sign * currentElement;
            sign *= -1;
        }
        signRow *= -1;
    }
    return matrix;
}

int main()
{
    int m = 7;
    int a = 3;
    int b = 1;
    int c = 4;
    int** matrix = createMatrix(m, a, b, c);
    for (int i = 0; i < m; i++) {
        int currentSize = 0;

        if (i % 3 == 0) {
            currentSize = a;
        }
        else if (i % 3 == 1) {
            currentSize = b;
        }
        else {
            currentSize = c;
        }

        for (int j = 0; j < currentSize; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}