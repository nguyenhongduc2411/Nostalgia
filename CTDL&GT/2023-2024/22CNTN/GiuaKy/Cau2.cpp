#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int n = right - left + 1;
    int* temp = new int[n];
    int idx = 0;

    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[idx++] = a[i++];
        }
        else
        {
            temp[idx++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[idx++] = a[i++];
    }

    while (j <= right)
    {
        temp[idx++] = a[j++];
    }

    for (int i = 0; i < n; i++)
    {
        a[left + i] = temp[i];
    }

    delete[] temp;
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

/*

Radix sort
Counting sort

O(n * d)

*/

int Sum(int a[], int b[], int n, int k)
{
    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, n - 1);

    int i = 0, j = n - 1;

    while (i < n && j >= 0)
    {
        if (a[i] + b[j] == k)
            return 1;

        if (a[i] + b[j] < k)
            i++;
        else // a[i] + b[j] > k
            j--;
    }

    return 0;
}

int main()
{
    vector<int> a = { 6, 5, 4, 3, 2, 1 };
    vector<int> b = { 12, 11, 10, 9, 8, 7 };

    cout << Sum(&a[0], &b[0], a.size(), 13);

    return 0;
}