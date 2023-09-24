#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int tongSoNguyen(const char* s)
{
    int n = strlen(s);
    int sum = 0;
    string num;

    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];
        }
        else {
            if (!num.empty()) {
                sum += stoi(num);
                num.clear();
            }
        }
    }
    if (!num.empty()) {
        sum += stoi(num);
    }

    return sum;
}

int main()
{
    string s = "aa11b33";
    cout << tongSoNguyen(s.c_str()) << "\n";

    s = "7 11";
    cout << tongSoNguyen(s.c_str()) << "\n";

    s = "1.2.3.4";
    cout << tongSoNguyen(s.c_str()) << "\n";

    return 0;
}