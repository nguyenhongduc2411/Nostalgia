#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

00
01
10
11

0001010101101
0000000111111
111111

Chỉ quan tâm số lượng số 0 và số lượng số 1

001110001111
k! / (cnt0! * cnt1!) -> Dính tới phép chia

Mod 1e9 + 7

9! / (5! * 4!)
9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
(5 * 4 * 3 * 2 * 1) * (4 * 3 * 2 * 1)

9C5 * 4C4

C[k][i] * C[k - i][j]
= C[k][i] * C[j][j]
= C[k][i] * 1

*/

const int M = 1e9 + 7;
const int N = 1000;
ll C[N + 1][N + 1]; // n choose k

// O(n^2)
// Precomputation
void precalc()
{
    C[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        C[n][0] = 1;
        C[n][n] = 1;

        for (int k = 1; k < n; k++) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            C[n][k] %= M;
        }
    }
}

// O(n^2)
void solve()
{
    precalc();

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt0 = 0;
    int cnt1 = 0;

    for (char c : s) {
        if (c == '0')
            cnt0++;
        else
            cnt1++;
    }

    ll ans = 0;

    for (int i = cnt0; i >= 0; i -= 2) {
        for (int j = cnt1; j >= 0; j -= 3) {
            if (i + j == k) {
                ll first = C[k][i];
                ll second = C[k - i][j];

                if (second != 1)
                    assert(false);

                ll cur = first * second;
                cur %= M;

                ans += cur;
                ans %= M;
            }
        }
    }

    cout << ans;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());

    ofstream out("output.txt");
    cout.rdbuf(out.rdbuf());

    solve();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}