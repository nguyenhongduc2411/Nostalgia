#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    struct tm t = {0}; // Nên khởi tạo như thế này cho an toàn
    scanf("%d-%d-%d %d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec);

    t.tm_year -= 1900;
    t.tm_mon--;

    // Time zone GMT+00:00
    time_t ans = mktime(&t);
    cout << ans << "\n";

    // Time zone GMT+07:00
    // https://cplusplus.com/reference/ctime/mktime/
    // "the values of the other members are interpreted even if out of their valid ranges"
    t.tm_hour += 7;
    ans = mktime(&t);
    cout << ans << "\n";
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

    solve();

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cerr << "Time taken by function: " << duration.count() << " milliseconds";

    return 0;
}