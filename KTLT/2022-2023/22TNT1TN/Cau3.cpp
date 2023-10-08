#include <iostream>
#include <vector>
using namespace std;

/*

3 6 15 16 21
1 1 2  2  1

Giải thuật:
Sử dụng quay lui để thử tất cả các trường hợp:
- Đi qua từng tờ tiền, thử cho tờ tiền đó cho từng thợ mỏ
- Khi có 1 phân hoạch thì kiểm tra xem chênh lệch có nhỏ hơn chênh lệch nhỏ nhất hiện tại hay không
  - Nếu nhỏ hơn thì lưu lại phân hoạch
- Sau cùng ta sẽ có phân hoạch tối ưu

*/

int* bestPartition;
int bestDiff = INT_MAX;

void backtrack(int a[], int n, int k, int partition[], int coinIndex)
{
    if (coinIndex >= n) {
        int* sum = new int[k];
        for (int i = 0; i < k; i++) {
            sum[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            sum[partition[i]] += a[i];
        }

        int minSum = sum[0];
        int maxSum = sum[0];
        for (int i = 1; i < k; i++) {
            minSum = min(minSum, sum[i]);
            maxSum = max(maxSum, sum[i]);
        }

        if (maxSum - minSum < bestDiff) {
            bestDiff = maxSum - minSum;
            for (int i = 0; i < n; i++) {
                bestPartition[i] = partition[i] + 1;
            }
        }

        delete sum;

        return;
    }

    for (int i = 0; i < k; i++) {
        partition[coinIndex] = i;
        backtrack(a, n, k, partition, coinIndex + 1);
    }
}

int* getPartition(int a[], int n, int k) {
    int* partition = new int[n];
    bestPartition = new int[n];

    backtrack(a, n, k, partition, 0);

    delete partition;

    return bestPartition;
}

int main()
{
    vector<int> a = {3, 6, 15, 16, 21};
    int* partition = getPartition(&a[0], a.size(), 2);

    for (int i = 0; i < a.size(); i++) {
        cout << partition[i] << " ";
    }

    delete partition;

    return 0;
}