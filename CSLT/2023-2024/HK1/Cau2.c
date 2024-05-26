#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);

    double S = 0;

    for (int i = 1; i <= n; i++) {
        S = sqrt(2 + S);
    }

    printf("%f", S);

    return 0;
}