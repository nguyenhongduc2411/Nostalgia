#include <iostream>
#include <cassert>
using namespace std;

/*

Min-heap:
Đối với tất cả các chỉ số i
- pq[i] <= pq[i * 2 + 1]
- pq[i] <= pq[i * 2 + 2]
- pq[i] <= min(pq[i * 2 + 1], pq[i * 2 + 2])

- Sift up: Từ 1 vị trí idx nào đó, thì ta sẽ đảm bảo tính chất của heap 
  từ vị trí đó lên trên các node ancestors (tiền bối) của nó

- Sift down: Từ 1 vị trí idx nào đó, thì ta sẽ đảm bảo tính chất của heap 
  từ vị trí đó xuống các node con cháu của nó

10 15 30 40 50 100 40
0  1  2  3  4  5   6

(3 - 1) / 2 = 1
(4 - 1) / 2 = 3/2 = 1
(5 - 1) / 2 = 4/2 = 2

10 9 8 7 6 5 4 3 2
0  1 2 3 4 5 6 7 8

10 / 2 - 1 = 4
9 / 2 - 1 = 4 - 1 = 3

*/

void siftdown(int pq[], int n, int idx)
{
    while (idx * 2 + 1 < n) {
        // Tìm child nhỏ hơn giữa 2 child (Nếu có child thứ 2)
        int childIdx = idx * 2 + 1;
        int childIdx2 = idx * 2 + 2;
        if (childIdx2 < n && pq[childIdx2] < pq[childIdx])
            childIdx = childIdx2;

        // Đã thỏa điều kiện của heap
        if (pq[idx] <= pq[childIdx])
            break;

        swap(pq[idx], pq[childIdx]);
        idx = childIdx;
    }
}

void siftup(int pq[], int n, int idx)
{
    while (idx > 0) {
        int parentIdx = (idx - 1) / 2;

        // Đã thỏa điều kiện của heap
        if (pq[parentIdx] <= pq[idx])
            break;

        swap(pq[parentIdx], pq[idx]);
        idx = parentIdx;
    }
}

void updatePQ(int pq[], int n, int idx)
{
    siftdown(pq, n, idx);
    siftup(pq, n, idx);
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
            assert(pq[i] <= pq[i * 2 + 1]);

        if (i * 2 + 2 < n)
            assert(pq[i] <= pq[i * 2 + 2]);
    }
}

int main()
{
    int pq[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(pq) / sizeof(*pq);

    buildPQ(pq, n);
    validatePQ(pq, n);
    for (int i = 0; i < n; i++) {
        cout << pq[i] << " ";
    }
    cout << "\n";

    int idx = 3;
    pq[idx] = 20;
    updatePQ(pq, n, idx);

    validatePQ(pq, n);
    for (int i = 0; i < n; i++) {
        cout << pq[i] << " ";
    }
    cout << "\n";

    return 0;
}