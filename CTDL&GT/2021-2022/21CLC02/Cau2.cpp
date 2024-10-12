#include <iostream>
using namespace std;

/*

1 3 5 7 9 11

5 7 9 11 1 3
0 1 2 3  4 5
m = 2

*/

int searchArray(int a[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (a[m] == k)
            return m;

        // Phần bên trái được sort
        if (a[l] <= a[m]) {
            if (a[l] <= k && k < a[m]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        // Phần bên phải được sort
        else {
            if (a[m] < k && k <= a[r]) {
                l = m + 1; 
            }
            else {
                r = m - 1;
            }
        }
    }
    return -1;
}

int main()
{
    {
        int a[] = {7, 9, 11, 1, 3, 5};
        int n = sizeof(a) / sizeof(*a);
        int k = 3;
        cout << searchArray(a, n, k) << "\n";
    }

    {
        int a[] = {9, 11, 1, 3, 5, 7};
        int n = sizeof(a) / sizeof(*a);
        int k = 11;
        cout << searchArray(a, n, k) << "\n";
    }

    {
        int a[] = {3, 5, 7, 9, 11, 1};
        int n = sizeof(a) / sizeof(*a);
        int k = 10;
        cout << searchArray(a, n, k) << "\n";
    }

    return 0;
}