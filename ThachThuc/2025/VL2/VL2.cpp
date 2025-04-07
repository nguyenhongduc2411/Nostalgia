#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
// Counting, mapping, frequency
void solve()
{
    string s;
    cin >> s;

    vector<int> freq(26);
    for (char c : s) {
        freq[c - 'a']++;
    }

    map<int, int> mp;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            mp[freq[i]]++;
        }
    }

    if (mp.size() == 1) {
        cout << "YES\n";
        return;
    }

    if (mp.size() == 2) {
        auto it = mp.begin();
        auto it2 = ++mp.begin();

        // if (it->second == 1 || it2->second == 1) {
        //     cout << "YES\n";
        //     return;
        // }

        // Swap cho thằng it->first sẽ <= it2->first
        if (it->first > it2->first)
            swap(it, it2);

        // it->first <= it2->first
        if (it2->first - 1 == it->first && it2->second == 1) {
            cout << "YES\n";
            return;
        }

        if (it->first == 1 && it->second == 1)  {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}