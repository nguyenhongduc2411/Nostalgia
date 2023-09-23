#include <stdio.h>

/*

2^3
= 2 * 2 * 2

2 * 3
= 2 + 2 + 2
= 3 + 3

*/

long long multiply(int x, int y)
{
    long long ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += y;
    }
    return ans;
}

long long power(int x, int y)
{
    long long ans = 1;
    for (int i = 1; i <= y; i++) {
        ans = multiply(ans, x);
    }
    return ans;
}

int main()
{
    // printf("%d\n", power(0, 0));
    printf("%d\n", power(0, 1));
    printf("%d\n", power(0, 2));
    printf("%d\n", power(0, 3));
    printf("%d\n", power(0, 4));
    printf("\n");

    printf("%d\n", power(1, 0));
    printf("%d\n", power(1, 1));
    printf("%d\n", power(1, 2));
    printf("%d\n", power(1, 3));
    printf("%d\n", power(1, 4));
    printf("\n");

    printf("%d\n", power(2, 0));
    printf("%d\n", power(2, 1));
    printf("%d\n", power(2, 2));
    printf("%d\n", power(2, 3));
    printf("%d\n", power(2, 4));
    printf("\n");

    printf("%d\n", power(3, 0));
    printf("%d\n", power(3, 1));
    printf("%d\n", power(3, 2));
    printf("%d\n", power(3, 3));
    printf("%d\n", power(3, 4));
    printf("\n");

    return 0;
}