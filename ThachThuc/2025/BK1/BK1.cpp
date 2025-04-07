#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Subtask 1: Brute force
// O(n * q)
void solve()
{
    int n, q;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] += x;
            ans += abs(a[i]);
        }
        cout << ans << "\n";
    }
}

// O(q * log(n))

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}