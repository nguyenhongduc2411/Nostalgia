#include <iostream>
#include <cmath>
using namespace std;

/*

k * floor(sqrt(k)) + ceil(k / 2)
= k * (int)sqrt(k) + (k + 1) / 2
Hàm này là hàm tăng dần
=> Nhảy 1 bước nhảy của số nhỏ hơn thì cùng lắm chỉ tới được số tiếp theo (Chứ ko thể tới số sau số tiếp theo)
=> Nhảy từ 1 thì cùng lắm chỉ tới 2, chứ ko thể tới 3

1 1 1 1 2 2 2 2 2 3 3 3 3
      L R   .

*/

int numOfDistinctInts(int a[], int L, int R)
{
    int i = L;
    int prev = -1;
    int cnt = 0;
    while (i <= R) {
        int k = a[i];
        if (k != prev) {
            cnt++;
            prev = k;
        }

        i += k * (int)sqrt(k) + (k + 1) / 2;
        if (i > R) {
            if (a[R] != k) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int a[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
    int n = sizeof(a) / sizeof(*a);
    cout << numOfDistinctInts(a, 6, 7);

    // for (int i = 1; i <= 10; i++) {
    //     int k = i;
    //     int idx = k * (int)sqrt(k) + (k + 1) / 2;
    //     cout << idx << " ";
    // }

    return 0;
}