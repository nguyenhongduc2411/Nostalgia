#include <iostream>
using namespace std;

/*

a)
f(3) = 10/3 = 3.33333...
f(5) = 225/43 = 5.23255...

b)
f(1) = 1
f(n) = n + 1/f(n - 1)

*/

double continuedFrac(int n)
{
    // Cẩn thận thì thêm điều kiện này
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    return n + 1.0 / continuedFrac(n - 1);
}

int main()
{
    cout << continuedFrac(3) << "\n";
    cout << continuedFrac(5) << "\n";

    return 0;
}