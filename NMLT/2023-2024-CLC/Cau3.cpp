#include <iostream>
#include <string.h>
using namespace std;

/*

aaa -> 111
zzz -> 252525

zzzzzzzz -> 2525252525252525 > INT_MAX

*/

long long getValue(char str[])
{
    long long sum = 0;
    long long factor = 1;

    int n = strlen(str);
    for (int i = n - 1; i >= 0; i--) {
        int value = str[i] - 'a';
        sum += value * factor;

        if (value < 10)
            factor *= 10;
        else
            factor *= 100;
    }

    // cout << sum << "\n";
    return sum;
}

bool checkEqual(char first[], char second[], char target[])
{
    return getValue(first) + getValue(second) == getValue(target);
}

int main()
{
    char first[] = "zzzazzbz";
    char second[] = "aaaaaaaa";
    char target[] = "zzzzzzzz";
    cout << checkEqual(first, second, target) << "\n";

    return 0;
}