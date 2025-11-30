#include <stdio.h>
#include <iostream>
using namespace std;

int findNumberKTimesPerRow(int a[][100], int M, int N, int K)
{
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = i; j < N; j++) {
            if (a[0][i] == a[0][j]) {
                cnt++;
            }
        }
        if (cnt == K)
            return a[0][i];
    }
    return -1;
}

int main()
{
    {
        int a[][100] = {
            {1, 2, 3, 4, 5, 3, 6},
            {2, 7, 3, 1, 3, 5, 9},
            {8, 5, 3, 9, 0, 1, 3}
        };
        cout << findNumberKTimesPerRow(a, 3, 7, 2);
    }

    return 0;
}