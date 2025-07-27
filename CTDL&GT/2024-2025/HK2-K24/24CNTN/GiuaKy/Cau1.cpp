#include <iostream>
using namespace std;

// <= kích thước này thì sử dụng insertion sort
const int THRESHOLD = 10;

void insertionSort(int a[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int cur = a[i];
        int j = i;
        while (j > left && a[j - 1] > cur) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = cur;
    }
}

void merge(int a[], int left, int mid, int right)
{
    int n = right - left + 1;
    int* temp = new int[n];

    int i = left, j = mid + 1;
    int idx = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[idx++] = a[i++];
        }
        else {
            temp[idx++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[idx++] = a[i++];
    }

    while (j <= right) {
        temp[idx++] = a[j++];
    }

    for (int i = 0; i < n; i++) {
        a[left + i] = temp[i];
    }

    delete[] temp;
}

void enhancedMergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;

    if (right - left + 1 <= THRESHOLD) {
        insertionSort(a, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    enhancedMergeSort(a, left, mid);
    enhancedMergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main()
{
    int a[] = {9, 8, 2, 1, 7, 9, 6, 8, 6, 5, 4, 5, 3};
    int n = sizeof(a) / sizeof(*a);
    enhancedMergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}