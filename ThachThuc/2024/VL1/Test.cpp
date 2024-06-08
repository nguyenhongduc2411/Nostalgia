#include <bits/stdc++.h>
using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    ofstream out("input.txt");
    cout.rdbuf(out.rdbuf());

    const int MAX = 1e6;
    uniform_int_distribution<int> distribution(0, MAX); // Xài distribution này để tận dụng phân phối đều

    int n;
    cin >> n;
    cout << n << "\n";
    
    for (int i = 0; i < n; i++) {
        int num = distribution(rng);
        cout << num << " ";
    }

    return 0;
}