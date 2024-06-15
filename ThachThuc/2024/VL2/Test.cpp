#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ofstream out("input.txt");
    cout.rdbuf(out.rdbuf());

    const ll MAX = 1e18;
    uniform_int_distribution<ll> distribution(1, MAX); // Xài distribution này để tận dụng phân phối đều

    int n;
    cin >> n;
    cout << n << "\n";
    
    for (int i = 0; i < n; i++) {
        ll num = distribution(rng);
        cout << num << "\n";
    }

    return 0;
}