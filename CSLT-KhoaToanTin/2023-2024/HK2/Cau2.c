#include <stdio.h>

/*

S = a^0/(0 + 1) + a^1/(1 + 1) + a^2/(2 + 1) + a^3/(3 + 1) + ... + a^n/(n + 1)

*/

int main()
{
    int a, n;
    scanf("%d %d", &a, &n);

    double S = 0;
    double tuso = 1;
    double mauso = 1;

    for (int i = 0; i <= n; i++) {
        S += tuso/mauso;
        tuso *= a;
        mauso++;
    }

    printf("%lf", S);

    return 0;
}