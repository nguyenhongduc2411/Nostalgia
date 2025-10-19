class Solution {
public:
    int maxDistinctElements(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        // Lưu lại thằng prev và thằng hiện tại bắt buộc là > prev
        int prev = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = max(prev + 1, a[i] - k);
            if (cur <= a[i] + k) {
                ans++;
                prev = cur;
            }
        }
        return ans;
    }
};