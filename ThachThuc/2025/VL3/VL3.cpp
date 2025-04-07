#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

10 5
1 2 3 4 5 6 7 8 9 10
1 7
1 8
1 9
2 4
2 5

90 + 10 * 4

130 + 10 * 5

*/

// https://lqdoj.edu.vn/problem/queryevenodd
// Math - Parity (Odd, even)
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sumeven = 0, sumodd = 0;
    ll cnteven = 0, cntodd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sumeven += a[i];
            cnteven++;
        }
        else {
            sumodd += a[i];
            cntodd++;
        }
    }
    // cout << "sumodd: " << sumodd << "; sumeven: " << sumeven << "\n";

    while (q--) {
        int t, x;
        cin >> t >> x;
        // Increase all evens
        if (t == 1) {
            // even + even == even
            // even + odd = odd

            if (x % 2 == 0)  {
                sumeven += cnteven * x;
            }
            else {
                // Even becomes odd
                sumodd += sumeven + cnteven * x;
                cntodd += cnteven;
                cnteven = 0;
                sumeven = 0;
            }
        }
        // Increase all odds
        else {
            // odd + even == odd
            // odd + odd == even

            if (x % 2 == 0) {
                sumodd += cntodd * x;
            }
            else {
                // Odd becomes even
                sumeven += sumodd + cntodd * x;
                cnteven += cntodd;
                cntodd = 0;
                sumodd = 0;
            }
        }

        // cout << "sumodd: " << sumodd << "; sumeven: " << sumeven << "\n";
        cout << sumodd + sumeven << "\n";
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }
    return 0;
}