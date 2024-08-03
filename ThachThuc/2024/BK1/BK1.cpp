#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<string> a(9);
    for (string& s : a)
        cin >> s;

    auto check = [&]() -> bool {
        unordered_set<char> vis; // visited

        // Check rows
        for (int i = 0; i < 9; i++) {
            vis.clear();
            for (int j = 0; j < 9; j++) {
                if (a[i][j] == '.')
                    continue;

                if (vis.find(a[i][j]) != vis.end())
                    return false;
                vis.insert(a[i][j]);
            }
        }

        // Check cols
        for (int j = 0; j < 9; j++) {
            vis.clear();
            for (int i = 0; i < 9; i++) {
                if (a[i][j] == '.')
                    continue;

                if (vis.find(a[i][j]) != vis.end())
                    return false;
                vis.insert(a[i][j]);
            }
        }

        auto check_square = [&](int r, int c) -> bool {
            vis.clear();
            for (int dr = 0; dr < 3; dr++) {
                for (int dc = 0; dc < 3; dc++) {
                    int i = r + dr;
                    int j = c + dc;

                    if (a[i][j] == '.')
                        continue;

                    if (vis.find(a[i][j]) != vis.end())
                        return false;
                    vis.insert(a[i][j]);
                }
            }
            return true;
        };

        // Check squares
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!check_square(i, j))
                    return false;
            }
        }
        return true;
    };

    if (check())
        cout << "VALID\n";
    else
        cout << "INVALID\n";
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    // ofstream out("output.txt");
    // cout.rdbuf(out.rdbuf());

    int t;
    cin >> t;
    while (t--)
        solve();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}