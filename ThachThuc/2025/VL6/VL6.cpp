#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> cache;

// https://lqdoj.edu.vn/problem/21ts10dna3
// Number theory, precomputation
void solve() {
    int l, r;
    cin >> l >> r;

    auto it = lower_bound(cache.begin(), cache.end(), l);
    auto it2 = upper_bound(cache.begin(), cache.end(), r);
    int ans = distance(it, it2);
    cout << ans << "\n";
}

int main()
{
    const int MAX = 3e6;
    vector<bool> prime(MAX + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= MAX; i++) {
        if (!prime[i])
            continue;

        for (ll j = (ll)i * i; j <= MAX; j += i) {
            prime[j] = false;
        }
    }

    for (int i = 2; i <= MAX; i++) {
        if (!prime[i])
            continue;
        
        int sum = 0;
        int num = i;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum % 5 == 0) {
            cache.push_back(i);
        }
    }

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}