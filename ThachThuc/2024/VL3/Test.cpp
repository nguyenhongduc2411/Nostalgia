#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ofstream out("input.txt");
    cout.rdbuf(out.rdbuf());

    uniform_int_distribution<ll> distribution(0, 1); // Xài distribution này để tận dụng phân phối đều

    int n, k;
    cin >> n >> k;
    cout << n << " " << k << "\n";
    
    for (int i = 0; i < n; i++) {
        int num = distribution(rng);
        cout << num;
    }

    return 0;
}