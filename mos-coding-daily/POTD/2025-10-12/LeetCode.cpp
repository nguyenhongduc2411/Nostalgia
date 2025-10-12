typedef long long ll;
const int N = 50;
const int M = 30;
const int K = 30;
ll dp[N][M + 1][K + 1][M + 1];

// Update this if needed
const int MOD = (int)1e9 + 7;
template<class T>
T mod(T a)
{
    T ret = a % MOD;
    if (ret < 0)
        ret += MOD;
    return ret;
}

template<class T>
T mul(T a, T b)
{
    return mod(mod(a) * mod(b));
}

template<class T>
T add(T a, T b)
{
    return mod(mod(a) + mod(b));
}

template<class T>
T binpow(T a, T b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll C[M + 1][M + 1] = {}; // n choose k

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        if (C[0][0] == 0) {
            C[0][0] = 1;
            for (int n = 1; n <= M; n++) {
                C[n][0] = 1;
                C[n][n] = 1;

                for (int k = 1; k < n; k++) {
                    C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
                    C[n][k] %= MOD;
                }
            }
        }

        int n = nums.size();

        for (int a = 0; a < n; a++) {
            for (int b = 0; b <= m; b++) {
                for (int c = 0; c <= k; c++) {
                    for (int d = 0; d <= m; d++) {
                        dp[a][b][c][d] = -1;
                    }
                }
            }
        }

        auto recur = [&](auto&& recur, int i, int remainchooses, int remainbits, int carry) -> ll {
            if (i == n) {
                if (remainchooses != 0)
                    return 0;

                int bits = __builtin_popcount(carry);
                return remainbits == bits ? 1 : 0;
            }

            auto& ans = dp[i][remainchooses][remainbits][carry];
            if (ans != -1)
                return ans;

            ans = 0;
            for (int choose = 0; choose <= remainchooses; choose++) {
                int sum = choose + carry;
                int curbit = sum % 2 == 1;
                int ncarry = sum / 2;
                int nremainbits = remainbits - curbit;
                if (nremainbits < 0)
                    continue;

                ll cur = C[remainchooses][choose];
                ll num = binpow((ll)nums[i], (ll)choose, MOD);
                ll next = recur(recur, i + 1, remainchooses - choose, nremainbits, ncarry);
                cur = mul(cur, mul(num, next));
                ans = add(ans, cur);
            }
            return ans;
        };

        return recur(recur, 0, m, k, 0);
    }
};