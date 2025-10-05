#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<unordered_set<int>> students(n);

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = i + 1;
        students[i].insert(b[i]);
    }

    vector<int> temp = b;

    while (true) {
        vector<int> next(n);
        for (int i = 0; i < n; i++) {
            next[a[i] - 1] = b[i]; 
        }

        // for (int u : next) {
        //     cout << u << " ";
        // }
        // cout << "\n";
        if (temp == next) {
            break;
        }

        b = next;
        for (int i = 0; i < n; i++) {
            students[i].insert(b[i]);
        }

        // for (int u : b) {
        //     cout << u << " ";
        // }
        // cout << "\n";
    }

    for (int i = 0; i < n; i++) {
        cout << students[i].size() << " ";
    }
}

void solve2()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> adj(n);
    for (int i = 0; i < n; i++) {
        adj[i] = a[i] - 1;
    }

    vector<int> comp(n);
    vector<int> ids(n, -1);
    int id = 0;

    auto dfs = [&](auto&& dfs, int u, int id) -> void {
        ids[u] = id;
        comp[id]++;

        if (ids[adj[u]] == -1) {
            dfs(dfs, adj[u], id);
        }
    };

    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            dfs(dfs, i, id++);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << comp[ids[i]] << " ";
    }
}

int main()
{
    // solve1();
    solve2();
}