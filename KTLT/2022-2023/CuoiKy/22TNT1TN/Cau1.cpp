#include <iostream>
using namespace std;

char* toBitString(int N)
{
    int count = 0;
    int temp = N;
    while (temp > 0) {
        temp /= 2;
        count++;
    }

    char* str = new char[count + 1];
    str[count] = '\0';
    int index = count - 1;

    while (N > 0) {
        str[index] = '0' + (N % 2);
        N /= 2;
        index--;
    }

    return str;
}

int main()
{
    cout << toBitString(10) << "\n";
    cout << toBitString(7) << "\n";
    return 0;
}