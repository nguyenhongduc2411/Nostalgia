#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Prefix sum
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    int m;
    cin >> m;
    ll best = LLONG_MIN;
    int ans = -1;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        int sum = pref[r] - pref[l - 1];
        if (sum >= best) {
            best = sum;
            ans = i;
        }
    }
    cout << ans;
}