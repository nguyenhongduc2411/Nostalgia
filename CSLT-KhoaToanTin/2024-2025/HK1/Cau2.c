#include <stdio.h>

/*

Nhập n
Gán P = 1
Vòng lặp i từ 1..n:
    Gán cur = 1
    Vòng lặp j từ 1..(n - i + 1):
        Gán cur = cur * i
    Thoát vòng lặp
    Gán P = P * cur
Thoát vòng lặp
Xuất P

*/

int main()
{
    int n;
    scanf("%d", &n);

    int P = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        for (int j = 1; j <= n - i + 1; j++) {
            cur *= i;
        }
        P *= cur;
    }

    printf("%d", P);

    return 0;
}