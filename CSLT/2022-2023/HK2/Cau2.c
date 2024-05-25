#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int S = 0;
    int P = 1; // Product

    for (int i = 1; i <= n; i++) {
        P *= i;
        S += P;
    }

    printf("%d", S);

    return 0;
}