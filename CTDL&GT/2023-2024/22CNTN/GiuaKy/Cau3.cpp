#include <iostream>
#include <vector>
using namespace std;

void MinMax(int a[], int n, int& min, int& max)
{
    if (n <= 0)
        return;

    min = a[0];
    max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        else if (a[i] > max)
            max = a[i];
    }

    // (n - 1) * 2
    // 2n - 2
}

/*

Giả sử mảng đã được sắp xếp không giảm
Thì không cần search gì vì min sẽ nằm ở đầu và max sẽ nằm ở cuối

*/

void MinMax2(int a[], int n, int& min, int& max)
{
    if (n <= 0)
        return;

    int start;

    // 1 phép so sánh
    if (n % 2 == 0)
    {
        if (a[0] < a[1])
        {
            min = a[0];
            max = a[1];
        }
        else
        {
            min = a[1];
            max = a[0];
        }

        start = 2;
    }
    // 0 phép so sánh
    else
    {
        min = a[0];
        max = a[0];

        start = 1;
    }

    for (int i = start; i + 1 < n; i += 2)
    {
        // 3 phép so sánh
        if (a[i] < a[i + 1])
        {
            if (a[i] < min)
                min = a[i];

            if (a[i + 1] > max)
                max = a[i + 1];
        }
        // a[i] >= a[i + 1]
        // 3 phép so sánh
        else
        {
            if (a[i] > max)
                max = a[i];

            if (a[i + 1] < min)
                min = a[i + 1];
        }
    }

    /*

    Chẵn phần tử:
    1 + 3 * (n - 2) / 2
    = 1 + (3n - 6) / 2
    = 1 + (3/2)n - 3
    = (3/2)n - 2

    Lẻ phần tử:
    3 * (n - 1) / 2
    = (3n - 3) / 2
    = (3/2)n - 3/2

    */
}

int main()
{
    vector<int> a = { 1, 5, 3, 7, 6, 2 };
    // 1 5 3 7 6 2 9
    // 1 5 3 7 6 2
    // min = 1
    // max = 5
    // 3 phép so sánh
    // n / 2
    // (3/2)n

    int min, max;
    MinMax2(&a[0], a.size(), min, max);
    cout << min << " " << max;

    return 0;
}