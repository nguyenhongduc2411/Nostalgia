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
    // Vì unix time chỉ có thể biễu diễn từ 1970-01-01 00:00:00 (GMT+00:00) trở đi
    // Tức là từ 1970-01-01 07:00:00 (GMT+07:00) trở đi, nên thời gian trước thời điểm này 
    // sẽ không biểu diễn được
    // -> Trường hợp thời gian từ 1970-01-01 06:59:59 trở về trước ta sẽ + thêm 7 tiếng rồi mới mktime
    if (t.tm_year == 70 && t.tm_mon == 0 && t.tm_mday == 1 && t.tm_hour < 7) {
        t.tm_hour += 7;
        time_t ans = mktime(&t);
        cout << ans << "\n";
    }
    // Trường hợp còn lại: Sau khi mktime thì mới + thêm 7 tiếng
    // (Vì sẽ có trường hợp + thêm 7 tiếng sẽ bị qua ngày tiếp theo)
    else {
        time_t ans = mktime(&t);
        ans += 7 * 60 * 60;
        cout << ans << "\n";
    }
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