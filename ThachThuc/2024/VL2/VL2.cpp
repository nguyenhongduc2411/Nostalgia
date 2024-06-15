#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

f[n] = f[n - 1] + f[n - 2]
f[5] = f[4] + f[3]
f[4] = f[3] + f[2]
f[3] = f[2] + f[1]

*/

const int M = 10;

const int N = 1e6 + 1;
ll dp[N] = {0};

// Top-down dp
ll fib(ll n)
{
    if (n <= 1)
        return 1;

    if (n == 2)
        return 2;

    if (dp[n] > 0)
        return dp[n];

    ll result = ((fib(n - 1) % M + fib(n - 2) % M)) % M;
    dp[n] = result;
    return result;
}

// O(n)
void solve1()
{
    ll n;
    cin >> n;

    // Top-down dp
    // cout << fib(n) << "\n";

    // Bottom-up dp
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (ll i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= M;
    }

    cout << dp[n] << "\n";
}

struct Matrix
{
    ll X[2][2] = {0};

    friend Matrix operator * (const Matrix& a, const Matrix& b)
    {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.X[i][j] += a.X[i][k] * b.X[k][j];
                    c.X[i][j] %= M;
                }
            }
        }
        return c;
    }
};

Matrix power(const Matrix& a, ll n)
{
    if (n == 1)
        return a;

    Matrix result = power(a, n / 2);

    if (n % 2 == 0)
        return result * result;
    return result * result * a;
}

// O(log(n))
void solve2()
{
    ll n;
    cin >> n;

    Matrix a;
    a.X[0][0] = 1;
    a.X[0][1] = 1;
    a.X[1][0] = 1;
    a.X[1][1] = 0;

    Matrix ans = power(a, n);
    cout << ans.X[0][0] << "\n";
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

    int t;
    cin >> t;
    while (t--) {
        // solve1();
        solve2();
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}