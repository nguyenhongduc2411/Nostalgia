#include <stdio.h>
#include <stdlib.h>

/*

Tìm tất cả các cặp dãy có cùng số phần tử
Tính tổng của 2 dãy
Lấy hiệu số của 2 dãy -> Chia hết cho k hay không

2, 4, 5, 3, 11
0  1  2  3  4

Xài bruteforce (Vét cạn)

*/

int getSum(int a[], int n, int start, int len)
{
    int sum = 0;
    int cnt = 0;
    for (int i = start; i < n && cnt < len; i++, cnt++) {
        sum += a[i];
    }
    if (cnt == len)
        return sum;
    return -1;
}

int coDayConTuongDuong(int a[], int n, int k)
{
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + len; j < n; j++) {
                int first = getSum(a, n, i, len);
                int second = getSum(a, n, j, len);

                if (first > 0 && second > 0 && (first - second) % k == 0) {
                    // printf("%d %d %d\n", i, j, len);
                    return 1;
                }
            }
        }
    }
    return 0;

    /*
    Ở câu này, khúc 55:44 trong video, chỗ lấy abs là abs(first - second) % k mình bị sai nhe :^)
    + Về cơ bản cách hiểu đúng sẽ là nếu (first - second) ra số âm thì khi thực hiện phép % k
      mình phải + thêm k rồi % k thêm 1 lần nữa
    + Tức là ví dụ mình gán: int temp = (first - second) % k thì mình phải
      làm thêm 1 bước: temp = (temp + k) % k; thì mới ra được phần dư đúng
    + Còn như ở đây bản chất dù nó là số dương chia hết cho k hay số âm chia hết cho k
      thì khi thực hiện % k cũng sẽ đều ra == 0
      (Trừ khi mình cần kiểm tra phần dư là một con số == 1 hay == 2 gì đó
      thì mới phải thực hiện temp = (temp + k) % k như ở trên)
    + Vậy nên chốt lại là bỏ abs đi và cách đúng sẽ là (first - second) % k == 0 ở đây :^)
    */
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int result = coDayConTuongDuong(a, n, k);
    if (result == 1)
        printf("Co hai day con tuong duong mo-dun %d.", k);
    else
        printf("Khong co hai day con tuong duong mo-dun %d.", k);

    return 0;
}