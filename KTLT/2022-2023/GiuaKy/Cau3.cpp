#include <stdio.h>
#include <iostream>
using namespace std;

int func1()
{
    return 100;
}

int func2()
{
    return 200;
}

int* func3()
{
    int* a = new int;
    cout << a << "\n";
    *a = 7789798;
    return a;
}

int *(*p()) ();
int *(*p()) () {
    return func3;
}

int main()
{
    // int a = 5;
    // const int* p = &a;
    // *p = 7; // Không hợp lệ

    // int a = 5;
    // int *const p = &a;
    // // int *const p2 = NULL;
    // *p = 7;
    // // p = NULL; // Không hợp lệ
    // printf("%d", a);

    // int (*const p[1000])() = {func1, func2};
    // cout << p[0]() << "\n";
    // cout << p[1]() << "\n";

    // int *(*p())();

    // cout << (p())();

    int (*p)() = func1;
    cout << p();

    return 0;
}