#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int>& arr, int low, int high)
{
    // Cài đặt quick sort
}

void customSort(vector<int>& arr)
{
    int n = arr.size();

    // O(n)
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (i >= j) {
            j++;
            continue;
        }

        if (arr[i] % 2 == 0 && arr[j] % 2 != 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;
            continue;
        }

        if (arr[i] % 2 != 0) {
            i++;
        }

        if (arr[j] % 2 == 0) {
            j++;
        }
    }

    // Selection sort
    // O(n^2)
    for (int i = n - 1; i >= 1; i--) {
        if (arr[i] % 2 != 0)
            break;

        int minIdx = i;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] % 2 != 0)
                break;

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (i != minIdx)
            swap(arr[i], arr[minIdx]);
    }

    int start = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            start = i;
        }
    }

    // Quick sort
    // Avg: O(n * log(n)), Worst case: O(n^2)
    // Chọn random index cho pivot -> Khó gặp Worst case
    if (start >= 0)
        quickSort(arr, start, n - 1);
}

int main()
{
    vector<int> arr = {7, 9, 13, 11, 2, 4, 8, 15, 16, 17};
    customSort(arr);

    for (const int& a : arr)
        cout << a << " ";

    return 0;
}