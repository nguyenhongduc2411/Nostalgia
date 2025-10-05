#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 2 && sum > a[i]) {
            ans = sum + a[i];
        }
        sum += a[i];
    }
    cout << ans;
}