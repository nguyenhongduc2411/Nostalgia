typedef long long ll;
unordered_map<ll, int> dp;
// Compress: Nén 3 số thành 1 số, rồi coi nó là key để đưa vào dp
class Solution {
public:
    int maxPartitionsAfterOperations(string& s, int k) {
        // Những kí tự đã xài
        // a -> Số lượng là 1
        // b -> Số lượng là 2
        // a -> Số lượng là 2
        // bitmask
        // Số 26 bit
        // Bật 1 bit lên thì là kí tự đó đã xài
        // Còn chưa bật thì chưa xài
        int n = s.size();

        // i: 13 bit
        // mask: 26 bit
        // used: 1 bit
        dp.clear();

        // Quy hoạch động: Recursive (Top down) và Iterative (Bottom up)

        auto recur = [&](auto&& recur, int i, int mask, bool used) -> int {
            if (i == n) {
                return 1;
            }

            ll key = i;
            key = (key << 26) | mask;
            key = (key << 1) | used;
            if (dp.count(key)) {
                return dp[key];
            }

            auto calc = [&](int j, bool used) -> int {
                int next = mask | (1 << j);
                int bitcount = __builtin_popcount(next); // Đếm số lượng bit đang bật
                if (bitcount > k) {
                    next = 1 << j;
                    return 1 + recur(recur, i + 1, next, used);
                }
                else {
                    return recur(recur, i + 1, next, used);
                }
            };

            int ans = 0;
            char c = s[i] - 'a'; // 0 - 25
            if (used) {
                ans = calc(c, used);
            }
            else {
                for (int j = 0; j < 26; j++) {
                    int cur = calc(j, j != c);
                    ans = max(ans, cur);
                }
            }
            return dp[key] = ans;
        };
        return recur(recur, 0, 0, false);
    }
};