#include <iostream>
using namespace std;

/*

4 / 2 = 2 dư 0
2 / 2 = 1 dư 0
1 / 2 = 0 dư 1
=> 100

Giải thuật đệ quy:
- Điều kiện dừng: N = 1 -> In ra 1
- Đệ quy:
  - Gọi InNhiPhaN(N / 2) để lần lượt thực hiện phép chia 2
  - Sau khi thực hiện xong đệ quy thì in ra N mod 2 là số nhị phân 0 hoặc 1

*/

void InNhiPhan(int N)
{
    if (N == 1) {
        cout << 1;
        return;
    }

    InNhiPhan(N / 2);
    cout << N % 2;
}

int main()
{
    for (int i = 1; i <= 10; i++) {
        InNhiPhan(i);
        cout << "\n";
    }
    return 0;
}