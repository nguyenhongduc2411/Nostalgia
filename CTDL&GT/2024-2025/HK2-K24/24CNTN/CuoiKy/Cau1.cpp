#include <iostream>
#include <cassert>
using namespace std;

// Quick select: Average O(n)

// Chia phần bên trái là <= pivot, phần bên phải > pivot
int partition(double a[], int left, int right)
{
    int n = right - left + 1;
    int chosen = left + rand() % n;
    swap(a[chosen], a[right]);

    double pivot = a[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[right]);
    return i;
}

double quickSelect(double a[], int left, int right, int k)
{
    if (left == right)
        return a[left];

    int pivotIdx = partition(a, left, right);
    if (pivotIdx == k)
        return a[pivotIdx];
    else if (pivotIdx < k)
        return quickSelect(a, pivotIdx + 1, right, k);
    else
        return quickSelect(a, left, pivotIdx - 1, k);
}

// Cách đệ quy
double kthElement(double a[], int n, int k)
{
    return quickSelect(a, 0, n - 1, k - 1);
}

// Cách không đệ quy
double kthElementIterative(double a[], int n, int k)
{
    k--;
    int left = 0, right = n - 1;
    while (left <= right) {
        if (left == right)
            return a[left];

        int pivotIdx = partition(a, left, right);
        if (pivotIdx == k)
            return a[pivotIdx];
        else if (pivotIdx < k)
            left = pivotIdx + 1;
        else
            right = pivotIdx - 1;
    }
    assert(false); // Không thể tới được đây nếu tham số đầu vào hợp lệ
}

int main()
{
    double a[] = {5, 2, 4, 6,  3, 7, 1};
    int n = sizeof(a) / sizeof(*a);

    for (int i = 1; i <= n; i++) {
        cout << kthElementIterative(a, n, i) << " ";
    }

    return 0;
}