#include <bits/stdc++.h>
using namespace std;

/*

0
1 - 30: ... past ...
30 - 60: ... to ...
15 hoặc 45
30

*/

void solve(int h, int m)
{
    vector<string> names{"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
        "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    
    // int h, m;
    // cin >> h >> m;

    cout << h << ":" << m << " -> ";
    if (m == 0) {
        cout << names[h] << " o'clock";
    }
    else if (m == 15) {
        cout << "quarter past " << names[h];
    }
    else if (m == 45) {
        cout << "quarter to " << names[(h + 1) % 12];
    }
    else if (m == 30) {
        cout << "half past " << names[h];
    }
    else if (m < 30) {
        string name;
        if (m > 20)  {
            name = "twenty " + names[m - 20];
        }
        else {
            name = names[m];
        }
        if (m == 1) {
            cout << name << " minute past " << names[h];
        }
        else {
            cout << name << " minutes past " << names[h];
        }
    }
    // 30 < m < 60
    else {
        m = 60 - m;
        string name;
        if (m > 20) {
            name = "twenty " + names[m - 20];
        }
        else {
            name = names[m];
        }
        if (m == 1) {
            cout << name << " minute to " << names[(h + 1) % 12];
        }
        else {
            cout << name << " minutes to " << names[(h + 1) % 12];
        }
    }
    cout << "\n";
}

// Implementation
int main()
{
    for (int h = 1; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            solve(h, m);
        }
    }
   
    return 0;
}