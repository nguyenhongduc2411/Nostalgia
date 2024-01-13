#include <iostream>
using namespace std;

/*

30 -1 70 90
40
20
30 + 20 = 50


30 -1 70

-1 50 70

30 50 -1


*/

int restorePoint(int arr[], int n)
{
    if (n < 3)
        return 0;

    int diff = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        if (arr[i] < 0) {
            i++;
            continue;
        }

        if (arr[j] < 0) {
            j--;
            continue;
        }

        diff = arr[j] - arr[i];
        diff /= (j - i);
        break;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i == 0) {
                if (arr[i + 1] - diff >= 0) {
                    arr[i] = arr[i + 1] - diff;
                    return 1;
                }

            }
            else {
                arr[i] = arr[i - 1] + diff;
                return 1;
            }
        }
    }

    return 0;
}

void findLongestSequence(int arr[], int n, int& start, int& end)
{
    start = -1;
    end = -1;

    if (n < 3)
        return;

    int currentStart = 0;
    int currentEnd = 1;
    int currentDiff = arr[1] - arr[0];

    for (int i = 2; i < n; i++) {
        int diff = arr[i] - arr[i - 1];

        if (diff != currentDiff) {
            currentStart = i - 1;
            currentEnd = i;
            currentDiff = diff;
        }
        else {
            currentEnd++;

            if (currentDiff > 0 && currentEnd - currentStart + 1 >= 3) {
                if (start == -1 || currentEnd - currentStart >= end - start) {
                    start = currentStart;
                    end = currentEnd;
                }
            }
        }
    }
}

int main()
{
    // int a[] = {30, -1, 70, 90};
    // int n = sizeof(a) / sizeof(*a);

    // cout << restorePoint(a, n) << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }

    int a[] = {10, 10, 10, 11, 12};
    int n = sizeof(a) / sizeof(*a);
    int start, end;
    findLongestSequence(a, n, start, end);
    cout << "start = " << start << ", end = " << end;

    return 0;
}