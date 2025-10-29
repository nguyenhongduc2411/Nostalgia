// -----------------------------------------------------------------------------------
class Solution {
  public:
    int minCost(vector<int>& a) {
        priority_queue<int, vector<int>, greater<>> pq(a.begin(), a.end());
        int ans = 0;
        while (pq.size() > 1) {
            int u = pq.top();
            pq.pop();
            int v = pq.top();
            pq.pop();
            
            ans += u + v;
            pq.push(u + v);
            // cout << ans << " " << u << " " << v << "\n";
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
typedef array<int, 3> iii;
class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        
        // <sum, i, j>
        priority_queue<iii, vector<iii>, greater<>> pq;
        pq.push({a[0] + b[0], 0, 0});
        
        set<pair<int, int>> vis;
        vis.insert({0, 0});
        
        vector<vector<int>> ans;
        
        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({a[i], b[j]});
            // cout << a[i] << " " << b[j] << "\n";
            
            if (i + 1 < n && !vis.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], i + 1, j});
                vis.insert({i + 1, j});
            }
            if (j + 1 < m && !vis.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], i, j + 1});
                vis.insert({i, j + 1});
            }
        }
        return ans;
    }
};
typedef array<int, 3> iii;
class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> ans;
        ans.reserve(k);
        priority_queue<iii, vector<iii>, greater<>> pq;
        vector<int> c(n);
        vector<int> d(m);
        pq.push({a[0] + b[0], 0, 0});
        while (!pq.empty() && k--) {
            auto [u, i, j] = pq.top();
            pq.pop();
            ans.push_back({a[i], b[j]});
            if (j + 1 < m) {
                if (c[i] < j + 1) {
                    pq.push({a[i] + b[j + 1], i, j + 1});
                    c[i] = j + 1;
                    d[j + 1] = max(d[j + 1], i);
                }
            }
            if (i + 1 < n) {
                if (d[j] < i + 1) {
                    pq.push({a[i + 1] + b[j], i + 1, j});
                    d[j] = i + 1;
                    c[i + 1] = max(c[i + 1], j);
                }
            }
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------
typedef pair<int, int> ii;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& a) {
        // multi-source bfs
        int n = a.size();
        int m = a[0].size();
        
        queue<ii> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        
        int cnt = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                        continue;
                        
                    if (ans[ni][nj] != -1)
                        continue;
                    
                    q.push({ni, nj});
                    ans[ni][nj] = cnt;
                }
            }
            cnt++;
        }
        
        return ans;
    }
};

// -----------------------------------------------------------------------------------
class Solution {
  public:
    int diameter(int n, vector<vector<int>>& edges) {
        assert(edges.size() == n - 1);
        vector<vector<int>> adj(n);
        for (vector<int>& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        auto dfs = [&](auto&& dfs, int u, int p) -> int {
            int mx = 0;
            int smx = 0; // Second max
            for (int v : adj[u]) {
                if (v == p)
                    continue;
                
                int cur = dfs(dfs, v, u);
                if (cur > mx) {
                    smx = mx;
                    mx = cur;
                }
                else if (cur > smx) {
                    smx = cur;
                }
            }
            ans = max(ans, mx + smx);
            return mx + 1;
        };
        
        dfs(dfs, 0, -1);
        return ans;
    }
};

