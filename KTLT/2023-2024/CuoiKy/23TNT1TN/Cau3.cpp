#include <iostream>
using namespace std;

/*

A = {-3, 4, -2, 1, 2, [6], -1, 7}

S[i] (Sum array) = Tổng của subsequence thỏa đề kết thúc tại i
                 = max(A[i], max[0 <= j < i && A[j] < A[i]](S[j] + A[i]))
P[i] (Parent array) = Vị trí của phần tử trước đó của subsequence thỏa đề kết thúc tại i,
                      hoặc là -1 nếu là phần tử đầu tiên của subsequence đó
L[i] (Length array) = Chiều dài của subsequence thỏa đề kết thúc tại i

Subsequence thỏa đề sau cùng là subsequence có max S[i]

*/

void getBiggestSumIncreasingSubsequence(int A[], int n, int*& subSeq, int& subSeqSize)
{
    int* S = new int[n];
    int* P = new int[n];
    int* L = new int[n];
    for (int i = 0; i < n; i++) {
        S[i] = 0;
        P[i] = -1;
        L[i] = 1;
    }

    int maxSum = INT_MIN;
    int endIdx = -1;

    for (int i = 0; i < n; i++) {
        S[i] = A[i];

        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && S[j] + A[i] > S[i]) {
                S[i] = S[j] + A[i];
                P[i] = j;
                L[i] = L[j] + 1;
            }
        }

        if (S[i] > maxSum) {
            maxSum = S[i];
            endIdx = i;
        }
    }

    subSeqSize = (endIdx != -1 ? L[endIdx] : 0);
    subSeq = new int[subSeqSize];
    int subSeqIdx = subSeqSize - 1;

    while (endIdx != -1 && subSeqIdx >= 0) {
        subSeq[subSeqIdx] = A[endIdx];

        subSeqIdx--;
        endIdx = P[endIdx];
    }

    // cout << "S: ";
    // for (int i = 0; i < n; i++) {
    //     cout << S[i] << " ";
    // }
    // cout << "\n";

    // cout << "P: ";
    // for (int i = 0; i < n; i++) {
    //     cout << P[i] << " ";
    // }
    // cout << "\n";

    // cout << "L: ";
    // for (int i = 0; i < n; i++) {
    //     cout << L[i] << " ";
    // }
    // cout << "\n";

    delete[] S;
    delete[] P;
    delete[] L;
}

int main()
{
    int A[] = {-3, 4, -2, 1, 2, 6, -1, 7};
    int n = sizeof(A) / sizeof(*A);

    int* subSeq = nullptr;
    int subSeqSize = 0;
    getBiggestSumIncreasingSubsequence(A, n, subSeq, subSeqSize);

    for (int i = 0; i < subSeqSize; i++) {
        cout << subSeq[i] << " ";
    }
    cout << "\n";

    delete[] subSeq;

    return 0;
}