class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        int n = a.size();

        static array<int, 26> f;

        auto check = [](string& s, string& t) -> bool {
            f.fill(0);

            for (char c : s) {
                f[c - 'a']++;
            }
            for (char c : t) {
                f[c - 'a']--;
            }

            return count(f.begin(), f.end(), 0) == 26;
        };

        vector<string> ans;
        int i = 0;
        while (i < n) {
            string& s = a[i];
            while (i < n && check(s, a[i])) {
                i++;
            }
            ans.push_back(s);
        }
        return ans;
    }
};