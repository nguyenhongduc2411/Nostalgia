#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// O(n^2 * 14)
void solve1()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (string& s : a)
        cin >> s;

    auto check = [&](string a, string b) -> bool {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    };

    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(a[i], a[j]))
                ans++;
        }
    }
    cout << ans;
}

// O(n * 14)
void solve2()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (string& s : a)
        cin >> s;

    unordered_map<string, int> cnt;

    ll ans = 0;
    for (string& s : a) {
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '-')
                continue;

            string t = s;
            t[j] = '*';

            ll cur = cnt[t];
            ans += cur;

            cnt[t]++;
        }
    }
    cout << ans;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    // ofstream out("output.txt");
    // cout.rdbuf(out.rdbuf());

    // solve1();
    solve2();

    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}