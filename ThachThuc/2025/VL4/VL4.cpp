#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> cache;

void solve() {
    int n;
    cin >> n;

    // Tim vi tri > n 
    auto it = upper_bound(cache.begin(), cache.end(), (ll)n);
    cout << distance(cache.begin(), it);
}

// https://lqdoj.edu.vn/problem/brvthsg92025bnum
// Precomputation - Precalculation
int main()
{
    vector<ll> fib{1, 2};
    for (int i = 2; i <= 50; i++) {
        fib.push_back(fib[i - 2] + fib[i - 1]);
    }
    set<ll> s(fib.begin(), fib.end());

    vector<ll> nums;
    for (ll i = 1; i <= 1e5; i++) {
        ll cur = i * i;
        nums.push_back(cur);
    }

    for (ll u : nums) {
        ll sum = 0;
        ll temp = u;
        while (u > 0) {
            sum += u % 10;
            u /= 10;
        }

        if (s.count(sum)) {
            cache.push_back(temp);
            // cout << temp << "\n";
        }
    }

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}