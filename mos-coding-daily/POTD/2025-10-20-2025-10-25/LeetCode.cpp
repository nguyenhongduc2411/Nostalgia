// -----------------------------------------------------------------------------------
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string& s : operations) {
            if (s[1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
const int MAX = 1e5;
array<int, MAX + 1> f;
class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int ops) {
        int n = a.size();
        int ans = 0;
        sort(a.begin(), a.end());
        int mn = a.front();
        int mx = a.back();
        for (int u = mn; u <= mx; u++) {
            f[u] = 0;
        }
        for (int u : a) {
            f[u]++;
        }
        for (int u = mn; u <= mx; u++) {
            auto lit = lower_bound(a.begin(), a.end(), u - k);
            auto rit = upper_bound(a.begin(), a.end(), u + k);
            int cur = rit - lit;
            int temp = cur - f[u];
            //cout << cur << "\n";
            temp = min(temp, ops);
            ans = max(ans, f[u] + temp);
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
typedef long long ll;
unordered_map<int, int> f;
class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int ops) {
        int n = a.size();
        int ans = 0;
        sort(a.begin(), a.end());
        f.clear();
        for (int u : a) {
            f[u]++;
        }
        static const ll INF = 1e9;
        auto calc = [&](int u) -> void {
            auto lit = lower_bound(a.begin(), a.end(), u - k);
            auto rit = upper_bound(a.begin(), a.end(), min(INF, (ll)u + k));
            int cur = rit - lit;
            int cnt = f.count(u) ? f[u] : 0;
            int temp = cur - cnt;
            // cout << cur << "\n";
            temp = min(temp, ops);
            ans = max(ans, cnt + temp);
        };
        for (int i = 0; i < n; i++) {
            calc(a[i] - k);
            calc(a[i] + k);
            calc(a[i]);
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
public:
    bool hasSameDigits(string& s) {
        while (s.size() > 2) {
            for (int i = 0; i + 1 < s.size(); i++) {
                int d1 = s[i] - '0';
                int d2 = s[i + 1] - '0';
                int d = (d1 + d2) % 10;
                s[i] = (char)('0' + d);
            }
            s.pop_back();
        }
        return s[0] == s[1];
    }
};

// -----------------------------------------------------------------------------------
const int N = 4785;
array<int, N> cache{};
vector<int> a;
// 7777777
class Solution {
public:
    int nextBeautifulNumber(int n) {
        if (cache[0] == 0) {
            int idx = 0;
            // Lặp qua hết tất cả bitmask
            int all = 1 << 6;
            int ans = INT_MAX;
            // 1 2 3 4 5 6
            // Chọn ra các số nào đó trong các số 1, 2, 3, 4, 5, 6
            // (1, 3) (1, 4) (2, 5) (2, 6) (3, 4, 5) (1, 2, 6)
            for (int i = 1; i < all; i++) {
                int cur = 0;
                bool good = true;
                for (int j = 0; j < 6; j++) {
                    if (i & (1 << j)) {
                        int num = j + 1; // [0, 5] -> [1, 6]
                        for (int k = 0; k < num; k++) {
                            long long temp = cur * 10LL + num;
                            if (temp > INT_MAX) {
                                good = false;
                                break;
                            }
                            cur = temp;
                        }
                    }
                    if (!good)
                        break;
                }
                if (!good)
                    continue;

                // 1333
                // [3, 3, 3, 1]
                // [1, 3, 3, 3]

                a.clear();
                while (cur > 0) {
                    a.push_back(cur % 10);
                    cur /= 10;
                }
                reverse(a.begin(), a.end());

                // Đi qua hết tất cả permutation của cái mảng a
                do {
                    long long sum = 0;
                    for (int i = 0; i < a.size(); i++) {
                        sum = sum * 10 + a[i];
                    }
                    if (sum > INT_MAX)
                        break;
                    cache[idx++] = sum;
                } while (next_permutation(a.begin(), a.end()));
            }
            sort(cache.begin(), cache.end());
        }
        return *upper_bound(cache.begin(), cache.end(), n);
    }
};

// -----------------------------------------------------------------------------------
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int start = 1;
        while (n > 0) {
            int amount = min(n, 7);
            int end = start + amount - 1;
            ans += (start + end) * amount / 2;
            n -= amount;
            start++;
        }
        return ans;
    }
};