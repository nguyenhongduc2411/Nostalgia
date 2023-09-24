#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

S = "aabcde"
D =  110101

S' = abcd
D  = 1010

W = {"a", "bc", "de", "abc"}

123456
aabcde
  bc

Cần tìm canPartitionAt[4]
"bc" == "bc" trong chuỗi con của S[3..4]
canPartitionAt[4 - 2] = true
-> canParitionAt[4] = true

*/

// O(n * m * wordLength)
// wordLength là chiều dài lớn nhất cùa 1 trong các words
bool canPartition(string str, vector<string>& words)
{
    int n = str.length();
    int m = words.size();

    vector<bool> canPartitionAt(n + 1);
    canPartitionAt[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            string word = words[j];
            int wordLength = word.length();

            int startIdx = i - wordLength;

            if (startIdx < 0)
                continue;

            if (canPartitionAt[startIdx]) {
                if (word == str.substr(startIdx, wordLength)) {
                    canPartitionAt[i] = true;
                    break;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << canPartitionAt[i];
    // }
    // cout << "\n";

    return canPartitionAt[n];
}

int main()
{
    string str = "aabcde";
    vector<string> words = {"a", "bc", "de", "abc"};
    canPartition(str, words);
    return 0;
}