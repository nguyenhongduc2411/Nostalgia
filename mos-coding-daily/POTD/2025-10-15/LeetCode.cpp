class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& a) {
        int n = a.size();
        int i = 0;
        int prevcnt = 0;
        int ans = 0;
        while (i < n) {
            int prev = INT_MIN;
            int cnt = 0;
            while (i < n && a[i] > prev) {
                prev = a[i];
                i++;
                cnt++;
            }

            ans = max(ans, min(prevcnt, cnt));
            ans = max(ans, cnt / 2);

            prevcnt = cnt;
        }
        return ans;
    }
};