#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Next permutation

// O(n)
void solve()
{
    string s;
    cin >> s;

    if (next_permutation(s.begin(), s.end()))
        cout << s << "\n";
    else
        cout << "-1\n";
}

/*

112233[4]66655[5]444321

112233[5]66655[4]444321 (Swap)

1122335[123444455666] (Reverse)

321

*/

// O(n)
void solve2()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            for (int j = n - 1; j > i; j--) {
                if (s[j] > s[i]) {
                    swap(s[i], s[j]);
                    reverse(s.begin() + i + 1, s.end());
                    cout << s << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1\n";
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

    // solve();
    solve2();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}