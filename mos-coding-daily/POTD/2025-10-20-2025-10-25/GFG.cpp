// -----------------------------------------------------------------------------------
class Solution {
  public:
    vector<int> countBSTs(vector<int>& a) {
        int n = a.size();
        auto recur = [&](auto&& recur, int p, int mask, int mn, int mx) -> int {
            if (__builtin_popcount(mask) == n)
                return 1;
            
            int cntl = 0, cntr = 0;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    continue;
                    
                if (a[i] < mn || a[i] > mx)
                    continue;
                
                found = true;  
                if (a[i] < p) {
                    int next = mask | (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (a[j] > p - 1) {
                            next |= (1 << j);
                        }
                    }
                    cntl += recur(recur, a[i], next, mn, p - 1);
                }
                else {
                    int next = mask | (1 << i);
                    for (int j = 0; j < n; j++) {
                        if (a[j] < p + 1) {
                            next |= (1 << j);
                        }
                    }
                    cntr += recur(recur, a[i], next, p + 1, mx);
                }
            }
            if (cntl == 0)
                return cntr;
            if (cntr == 0)
                return cntl;
            return cntl * cntr;
        };
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = recur(recur, a[i], 1 << i, INT_MIN, INT_MAX);
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
const int MAX = 1e5;
array<int, MAX + 1> f;
class Solution {
  public:
    vector<int> topKFreq(vector<int> &a, int k) {
        f.fill(0);
        for (int u : a) {
            f[u]++;
        }
        vector<pair<int, int>> b;
        for (int u = 1; u <= MAX; u++) {
            if (f[u] > 0) {
                b.push_back({f[u], u});
            }
        }
        sort(b.rbegin(), b.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(b[i].second);
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
  public:
    void nearlySorted(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        int n = a.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                pq.push(a[i]);
            }
            else {
                pq.push(a[i]);
                a[idx++] = pq.top();
                pq.pop();
            }
        }
        while (idx < n) {
            a[idx++] = pq.top();
            pq.pop();
        }
    }
};

// -----------------------------------------------------------------------------------
typedef array<int, 3> iii;
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<iii> pq;
        auto calc = [](vector<int>& p) -> int {
            int dx = p[0] * p[0];
            int dy = p[1] * p[1];
            return dx + dy;
        };
        for (vector<int>& p : points) {
            int dist = calc(p);
            pq.push({dist, p[0], p[1]});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [dist, x, y] = pq.top();
            pq.pop();
            ans.push_back({x, y});
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
typedef pair<int, int> ii;
class Solution {
  public:
    bool isPossible(vector<int>& a, int k) {
        priority_queue<ii, vector<ii>, greater<>> pq;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (pq.empty()) {
                pq.emplace(a[i], 1);
            }
            else if (a[i] == pq.top().first + 1) {
                int len = pq.top().second;
                pq.pop();
                pq.emplace(a[i], len + 1);
            }
            else if (a[i] == pq.top().first) {
                pq.emplace(a[i], 1);
            }
            else {
                int len = pq.top().second;
                if (len < k)
                    return false;
                pq.pop();
                i--;
            }
        }
        while (!pq.empty()) {
            int len = pq.top().second;
            if (len < k)
                return false;
            pq.pop();
        }
        return true;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
  public:
    int minOperations(vector<int>& a) {
        priority_queue<double> pq(a.begin(), a.end());
        double sum = accumulate(a.begin(), a.end(), 0.0);
        double need = sum / 2;
        int ans = 0;
        while (sum > need) {
            double cur = pq.top() / 2;
            pq.pop();
            sum -= cur;
            pq.push(cur);
            ans++;
        }
        return ans;
    }
};