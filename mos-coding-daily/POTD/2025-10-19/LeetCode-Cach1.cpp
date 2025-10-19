class Solution {
public:
    string findLexSmallestString(string& s, int a, int b) {
        int n = s.size();
        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);
        string ans = s;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            ans = min(ans, s);

            string t = s;
            for (int i = 1; i < n; i += 2) {
                int d = t[i] - '0';
                d += a;
                d %= 10;
                t[i] = '0' + d;
            }
            if (!vis.count(t)) {
                q.push(t);
                vis.insert(t);
            }

            t = s;
            rotate(t.begin(), t.end() - b, t.end());
            if (!vis.count(t)) {
                q.push(t);
                vis.insert(t);
            }
        }
        return ans;
    }
};