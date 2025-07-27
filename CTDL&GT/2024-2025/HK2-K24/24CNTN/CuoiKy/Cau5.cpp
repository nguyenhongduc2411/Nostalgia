#include <iostream>
#include <cfloat>
using namespace std;

double divide(double x, double y)
{
    if (y == 0)
        return -1;

    // Cứ tìm tích m * y
    // => Tìm thằng m mà có m * y gần nhất với thằng x
    static const double EPS = 0.0001;
    double l = 0, r = DBL_MAX;
    while (r - l > EPS) {
        double m = l + (r - l) / 2;

        double cur = m * y; 
        if (cur < x) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l + (r - l) / 2;
}

int main()
{
    cout << divide(1, 107) << "\n";

    return 0;
}