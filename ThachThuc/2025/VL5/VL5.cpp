#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// https://codeforces.com/problemset/problem/1165/D
// Number theory
void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto [mn, mx] = minmax_element(a.begin(), a.end());
    set<ll> s(a.begin(), a.end());

    int cnt = 0;
    int cnt2 = 0;
    ll num = *mn * *mx;
    // O(sqrt(num))
    for (ll i = 1; i * i <= num; i++) {
        if (num % i != 0)
            continue;

        ll j = num / i;
        if (i == j) {
            if (s.count(i)) {
                cnt++;
                s.erase(i);
            }
            cnt2++;
        }
        else {
            if (s.count(i)) {
                cnt++;
                s.erase(i);
            }

            if (s.count(j)) {
                cnt++;
                s.erase(j);
            }

            cnt2 += 2;
        }
    }
    if (s.empty() && cnt + 2 == cnt2) {
        cout << num << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main()
{
    // ll num = 895671868951LL;
    // for (ll i = 1; i * i <= num; i++) {
    //     if (num % i != 0)
    //         continue;

    //     ll j = num / i;
    //     if (i == j) {
    //         cout << i << " ";
    //     }
    //     else {
    //         cout << i << " " << j << " ";
    //     }
    // }

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}