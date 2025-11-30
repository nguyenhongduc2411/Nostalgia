#include <stdio.h>
#include <iostream>
using namespace std;

void printMultiplicationTable(int range, int num)
{
    for (int i = 1; i <= range; i++) {
        // cout << num << " * " << i << " = " << (num * i) << "\n";
        printf("%d * %d = %d\n", num, i, num * i);
    }
}

int main()
{
    printMultiplicationTable(7, 14);
    return 0;
}