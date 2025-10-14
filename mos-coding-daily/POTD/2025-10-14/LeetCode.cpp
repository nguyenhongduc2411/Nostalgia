class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& a, int k) {
        int n = a.size();
        int i = 0;
        bool hasprev = false;
        while (i < n) {
            int prev = INT_MIN;
            int cnt = 0;
            while (i < n && a[i] > prev) {
                prev = a[i];
                i++;
                cnt++;
            }

            if (cnt >= k * 2)
                return true;

            if (cnt >= k && hasprev)
                return true;

            hasprev = cnt >= k;
        }
        return false;
    }
};