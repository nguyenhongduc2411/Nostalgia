typedef long long ll;
const int N = 1e5;
ll dp[N][4];
class Solution {
public:
    long long maximumTotalDamage(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = -1;
            }
        }
        // memset(dp, -1, sizeof(dp));
        // vector<vector<ll>> dp(n, vector<ll>(4, -1));

        auto recur = [&](auto&& recur, int i, int last) -> ll {
            if (i == n)
                return 0;

            int key = a[i] - last;
            key = min(key, 3);
            if (dp[i][key] != -1)
                return dp[i][key];

            ll ans = 0;
            ans = recur(recur, i + 1, last);

            if (a[i] == last || a[i] - last > 2) {
                ll cur = recur(recur, i + 1, a[i]) + a[i];
                ans = max(ans, cur);
            }

            return dp[i][key] = ans;
        };
        return recur(recur, 0, -5);
    }
};