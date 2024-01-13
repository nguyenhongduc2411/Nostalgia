#include <iostream>
using namespace std;

/*

1 3 7 13
2 4 6
2 2

1 3 7
2 4
2

*/

int findMaxCommonDifference(int a[], int n)
{
    int maxDiff = 0;
    for (int i = 0; i + 2 < n; i++) {
        int x1 = a[i + 1] - a[i];
        int x2 = a[i + 2] - a[i + 1];

        if (a[i] < a[i + 1] && a[i + 1] < a[i + 2]) {
            int diff = abs(x2 - x1);
            if (diff > maxDiff)
                maxDiff = diff;
        }
    }
    return maxDiff;
}

int main()
{
    int a[] = {3, 3, 3, 3};
    int n = sizeof(a) / sizeof(*a);
    cout << findMaxCommonDifference(a, n);

    return 0;
}