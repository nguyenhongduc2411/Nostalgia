#include <iostream>
#include <vector>
using namespace std;

/*

5 7 1 8 1 2

1 + 1 + 2 + 5 = 9

7 + 1 + 2 = 10
7 + 1 + 2 = 10
1 + 8 + 1 = 10

Tổng lớn nhất, mà còn có nhiều mặt hàng nhất
Tổng = 10
Và ở trường hợp này là 3 mặt hàng

*/

const int MAX_N = 100;
const int MAX_M = 100;

void print(int price[], int n, int m) {
    int dp[MAX_N][MAX_M];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            int first = dp[i - 1][j];
            int currentPriceIdx = i - 1;
            int second = 0;
            if (j - price[currentPriceIdx] >= 0)
                second = dp[i - 1][j - price[currentPriceIdx]] + price[currentPriceIdx];

            dp[i][j] = max(first, second);
            // if (dp[i][j] == 10) {
            //     cout << "(" << i << ", " << j << ")\n";
            // }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n][m] << "\n";
}

void print2(int price[], int n, int m) {
    // Muốn thử tất cả trường hợp có hoặc không có món hàng
    // 000000000
    // 111111111
    int all = 1;
    for (int i = 0; i < n; i++) {
        all *= 2;
    }
    cout << all << "\n";
    vector<vector<int>> solutions;
    int maxSum = 0;
    // 00000100
    // 00000001
    for (int i = 0; i < all; i++) {
        int sum = 0;
        vector<int> solution;
        for (int j = 0; j < n; j++) {
            bool isOn = (1 << j) & i;
            if (isOn) {
                sum += price[j];
                solution.push_back(j);
            }
            // cout << i << " " << j << "\n";
            // cout <<  isOn << " ";
        }
        // cout << "\n";
        if (sum <= m) {
            if (sum > maxSum) {
                maxSum = sum;
                solutions.clear();
                solutions.push_back(solution);
                // cout << "pushBack1";
            }
            else if (sum == maxSum) {
                if (!solutions.empty() && solutions.back().size() < solution.size()) {
                    solutions.clear();
                }
                if (solutions.empty() || solutions.back().size() == solution.size()) {
                    solutions.push_back(solution);
                }
                // cout << "pushBack2";
            }
        }
    }
    // cout << "sdfsdfsdf";
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int price[] = {5, 7, 1, 8, 1, 2};
    print(price, 6, 10);
    print2(price, 6, 10);
    return 0;
}