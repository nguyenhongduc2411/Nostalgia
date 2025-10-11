class Solution {
public:
    int maximumEnergy(vector<int>& a, int k) {
        int n = a.size();
        int ans = INT_MIN;
        for (int i = n - 1; i >= n - k; i--) {
            int sum = 0;
            for (int j = i; j >= 0; j -= k) {
                sum += a[j];
                ans = max(ans, sum);
            }   
        }
        return ans;
    }
};