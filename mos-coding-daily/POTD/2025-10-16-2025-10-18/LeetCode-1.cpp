const int N = 1e5;
array<int, N + 1> f;
class Solution {
public:
    int findSmallestInteger(vector<int>& a, int k) {
        int n = a.size();
        for (int& u : a) {
            u %= k;
            if (u < 0)
                u += k;
        }

        for (int i = 0; i <= k; i++) {
            f[i] = 0;
        }

        for (int u : a) {
            f[u]++;
        }

        for (int u = 0; u <= n; u++) {
            if (--f[u % k] < 0) {
                return u;
            }
        }
        assert(false);
    }
};