#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int reduceArray(int A[], int& N)
{
    int idx = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (!isPrime(A[i])) {
            A[idx] = A[i];
            idx++;
        }
        else {
            if (i == 0 || !isPrime(A[i - 1])) {
                A[idx] = A[i];
                cnt++;
            }
            else {
                A[idx] += A[i];
            }

            if (i == N - 1 || !isPrime(A[i + 1]))
                idx++;
        }
    }

    N = idx;
    return cnt;
}

int main()
{
    int A[] = {5, 2, 6, 7, 11, 8, 13, 5, 3, 15};
    int N = sizeof(A) / sizeof(*A);

    cout << "Reduce array: " << reduceArray(A, N) << "\n";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }

    return 0;
}