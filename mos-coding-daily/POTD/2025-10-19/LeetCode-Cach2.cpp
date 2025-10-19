class Solution {
public:
    string findLexSmallestString(string& s, int a, int b) {
        int n = s.size();

        int r = 0;
        bool hasoddr = false;
        do {
            r += b;
            r %= n;
            if (r % 2 != 0) {
                // Có nghĩa là các vị trí số chẵn có thể biến thành phần các vị trí số lẻ
                hasoddr = true;
            }
        } while (r != 0);

        vector<int> goods(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && !hasoddr)
                continue;

            int d = s[i] - '0';
            int mn = d;
            int cnt = 0;
            do {
                d += a;
                d %= 10;
                cnt++;
                if (d < mn) {
                    mn = d;
                    goods[i] = cnt;
                }
            } while (d != s[i] - '0');
        }

        string ans = s;
        r = 0;
        do {
            int good1 = goods[0];
            int good2 = goods[1];
            string t = s;
            for (int i = 0; i < n; i++) {
                int d = t[i] - '0';
                if (i % 2 == 0) {
                    d += good1 * a;
                }
                else {
                    d += good2 * a;
                }
                d %= 10;
                t[i] = '0' + d;
            }
            ans = min(ans, t);

            rotate(s.begin(), s.end() - b, s.end());
            rotate(goods.begin(), goods.end() - b, goods.end());

            r += b;
            r %= n;
        } while (r != 0);

        return ans;
    }
};