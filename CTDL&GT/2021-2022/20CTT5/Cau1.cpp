#include <iostream>
#include <cassert>
using namespace std;

// Max-heap
void siftdown(int pq[], int n, int idx)
{
    while (idx * 2 + 1 < n) {
        // Tìm child lớn hơn giữa 2 child (Nếu có child thứ 2)
        int childIdx = idx * 2 + 1;
        int childIdx2 = idx * 2 + 2;
        if (childIdx2 < n && pq[childIdx2] > pq[childIdx])
            childIdx = childIdx2;

        // Đã thỏa điều kiện của heap
        if (pq[idx] >= pq[childIdx])
            break;

        swap(pq[idx], pq[childIdx]);
        idx = childIdx;

        for (int i = 0; i < n; i++) {
            cout << pq[i] << " ";
        }
        cout << "\n";
    }
}

void siftup(int pq[], int n, int idx)
{
    while (idx > 0) {
        int parentIdx = (idx - 1) / 2;

        // Đã thỏa điều kiện của heap
        if (pq[parentIdx] >= pq[idx])
            break;

        swap(pq[parentIdx], pq[idx]);
        idx = parentIdx;
    }
}

void buildPQ(int pq[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftdown(pq, n, i);
    }
}

void validatePQ(int pq[], int n)
{
    for (int i = 0; i < n; i++) {
        if (i * 2 + 1 < n)
            assert(pq[i] >= pq[i * 2 + 1]);

        if (i * 2 + 2 < n)
            assert(pq[i] >= pq[i * 2 + 2]);
    }
}

/*
Câu a:
    // 5, 15, 12, 2, 10, 7, 4, 1, 9, 3
    // 0  1   2   3  4   5  6  7  8  9
    // 0: 1-2
    // 1: 3-4
    // 2: 5-6
    // 3: 7-8
    // 4: 9
    // 5, 15, 12, 9, 10, 7, 4, 1, 2, 3
    // 15, 10, 12, 9, 5, 7, 4, 1, 2, 3
Câu b: Heap sort
*/

// Điều kiện đầu vào: pq phải là max-heap
void heapSort(int pq[], int n)
{
    // Nếu pq chưa phải max-heap
    // buildPQ(pq, n);

    // Pop dần từng phần tử của Max-heap và swap với phần tử tương ứng tại vị trí của mảng
    for (int i = n - 1; i >= 0; i--) {
        // Swap phần tử lớn nhất của max-heap với phần tử tại vị trí của mảng
        swap(pq[0], pq[i]);

        // Siftdown tại vị trí 0 với kích thước max-heap đã giảm đi 1
        siftdown(pq, i, 0);
    }
}

int main()
{
    int pq[] = {5, 15, 12, 2, 10, 7, 4, 1, 9, 3};
    int n = sizeof(pq) / sizeof(*pq);

    buildPQ(pq, n);
    for (int i = 0; i < n; i++) {
        cout << pq[i] << " ";
    }
    cout << "\n";
    validatePQ(pq, n);

    heapSort(pq, n);
    for (int i = 0; i < n; i++) {
        cout << pq[i] << " ";
    }

    return 0;
}