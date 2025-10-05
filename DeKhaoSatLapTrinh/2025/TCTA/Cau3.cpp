#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n1, n2, m;
    cin >> n1 >> n2 >> m;

    int N = floor(((n1 + 1) * (n2 + 1)) / (m + 1) - 1);
    cout << N;
}