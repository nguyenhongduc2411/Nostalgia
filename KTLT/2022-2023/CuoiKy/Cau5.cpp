#include <iostream>
#include <stdio.h>
using namespace std;

void testing(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 5;
    int y = 10;
    testing(&x, &y);
    cout << "Result 1: " << x << endl;
    y = y - 2;
    int* z = &y;
    z++;
    cout << "Result 2: " << y-- << endl;
    cout << "Result 3: " << *z << endl; 
    cout << "Result 4: " << --z << endl;
    printf("%p\n", &x);
    printf("%p\n", &y);
    return 0;
}