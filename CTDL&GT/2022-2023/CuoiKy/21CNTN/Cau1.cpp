#include <iostream>
using namespace std;

const int m = 4;
const int n = 3;
const int INF = 100;

void print(int Y[m][n])
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << Y[i][j] << " ";
        }
        cout << "\n";
    }
}

// 2. O(m + n): Liên tưởng đến thao tác lấy phần tử min của heap, sau đó thực hiện sift down
int popMin(int Y[m][n])
{
    int i = 0, j = 0;
    while (true) {
        int right = j + 1 < n ? Y[i][j + 1] : INF;
        int down = i + 1 < m ? Y[i + 1][j] : INF;

        if (right == INF && down == INF) {
            int temp = Y[i][j];
            Y[i][j] = INF;
            return temp;
        }

        if (right <= down) {
            swap(Y[i][j], Y[i][j + 1]);
            j++;
        }
        else {
            swap(Y[i][j], Y[i + 1][j]);
            i++;
        }
    }
}

// 3. O(m + n): Liên tưởng đến thao tác thêm 1 phần tử vào heap (Thêm vào cuối của heap, sau đó thực hiện sift up)
void insert(int Y[m][n], int element)
{
    if (Y[m - 1][n - 1] != INF)
        return;

    int i = m - 1, j = n - 1;
    Y[i][j] = element;
    while (true) {
        int left = j - 1 >= 0 ? Y[i][j - 1] : -INF;
        int up = i - 1 >= 0 ? Y[i - 1][j] : -INF;

        if (Y[i][j] >= left && Y[i][j] >= up)
            break;

        if (left >= up) {
            swap(Y[i][j], Y[i][j - 1]);
            j--;
        }
        else {
            swap(Y[i][j], Y[i - 1][j]);
            i--;
        }
    }
}

// 4. Giả sử là n * n, thì O(n^3)
// O(n * n) * O(m + n)
// O(n^2) * O(n + n)
// O(n^2) * O(n)
// O(n^3)
// Liên tưởng đến thuật toán heap sort
void getSorted(int Y[m][n])
{
    while (Y[0][0] != INF) {
        cout << popMin(Y) << " ";
    }
    cout << "\n";
}

// 5. O(m + n): Liên tưởng đến một loại cây có tính chất gần giống cây nhị phân tìm kiếm (Không hẳn là cây nhị phân tìm kiếm) 
// Tính chất đó là mỗi node >= con bên trái và <= con bên phải (Nhưng đường đi thì không giống với cây nhị phân tìm kiếm)
bool search(int Y[m][n], int element)
{
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (Y[i][j] == element)
            return true;

        if (Y[i][j] > element)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    int Y[m][n] = {
        {2, 4, 9},
        {3, 5, 16},
        {8, 14, INF},
        {12, INF, INF}
    };

    cout << popMin(Y) << "\n";
    print(Y);
    cout << "\n";

    insert(Y, 2);
    print(Y);
    cout << "\n";

    // getSorted(Y);

    cout << search(Y, 7) << "\n";

    return 0;
}