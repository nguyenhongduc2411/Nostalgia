#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// O(n^4)
void solve1(vector<ll>& a)
{
    int n = a.size();
    ll ans = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ll sum = 0;
            for (int i = l; i + 1 <= r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    sum += a[i] * a[j];
                }
            }
            if (sum % 3 == 0) {
                // cout << l << " " << r << "\n";
                ans++;
            }
        }
    }

    cout << ans;
}

/*

dp[l..r], r + 1
dp[l..r + 1] = dp[l..r] + a[r + 1] * s[l..r]

s[l..r] = Tổng của các phần tử trong mảng từ l tới r

*/

const int N = 1000;
ll dp[N][N] = {0};
ll s[N][N] = {0};

// O(n^2)
void solve2(vector<ll>& a)
{
    int n = a.size();
    ll ans = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ll sum = 0;

            if (r - 1 >= 0) {
                sum += dp[l][r - 1] + a[r] * s[l][r - 1];

                s[l][r] = s[l][r - 1] + a[r];
            }
            else {
                s[l][r] = a[r];
            }

            dp[l][r] = sum;

            if (sum % 3 == 0) {
                // cout << l << " " << r << "\n";
                ans++;
            }
        }
    }

    cout << ans;
}

/*

0 1 2 3 4 5 6 7 8 9
0 1 2 0 1 2 0 1 2 0

5 5 5 5 5

(x + y)^2 = x^2 + 2xy + y^2

(x + y + z)^2 = x^2 + y^2 + z^2 + 2xy + 2xz + 2yz
xy + xz + yz = ((x + y + z)^2 - (x^2 + y^2 + z^2)) / 2

Tìm tổng mod 3 == 0

(x + y + z)^2 mod 3 == (x^2 + y^2 + z^2) mod 3

Prefix sum: Tính tổng từ phần tử đầu tiên đến phần tử nào đó

a[0] a[1] a[2] a[3] a[4] a[5]

{a, b} = {(x + y + z)^2 mod 3, (x^2 + y^2 + z^2) mod 3}

0 -> 2
0 0
0 1
0 2
1 0
1 1
1 2
2 0
2 1
2 2

*/

// O(n)
void solve3(vector<ll>& a)
{
    int n = a.size();
    ll ans = 0;

    ll dp[3][3] = {0};
    dp[0][0] = 1;

    ll first = 0;
    ll second = 0;

    for (int i = 0; i < n; i++) {
        first += a[i];
        second += a[i] * a[i];

        first %= 3;
        second %= 3;

        for (int x = 0; x <= 2; x++) {
            for (int y = 0; y <= 2; y++) {
                ll third = (first - x) * (first - x);
                ll fourth = second - y;

                third %= 3;
                fourth %= 3;

                if (third < 0)
                    third += 3;

                if (fourth < 0)
                    fourth += 3;

                if (third == fourth)
                    ans += dp[x][y];
            }
        }

        dp[first][second]++;
    }

    cout << ans;
}

int main()
{
    // auto start = chrono::high_resolution_clock::now();

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    // ofstream out("output.txt");
    // cout.rdbuf(out.rdbuf());

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // solve1(a);
    // solve2(a);
    solve3(a);

    // auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    // cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}