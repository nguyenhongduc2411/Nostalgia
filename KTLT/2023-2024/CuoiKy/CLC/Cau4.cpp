#include <iostream>
using namespace std;

void backtrack(const char* directors[], int N, int K, const char* chosens[], int idx, int start)
{
    if (idx == K) {
        cout << "{";
        for (int i = 0; i < K; i++) {
            cout << "\"" << chosens[i] << "\"";
            if (i + 1 < K)
                cout << ", ";
        }
        cout << "}";
        cout << "\n";

        return;
    }

    for (int i = start; i < N; i++) {
        chosens[idx] = directors[i];
        backtrack(directors, N, K, chosens, idx + 1, i + 1);
        chosens[idx] = "";
    }
}

void generate(const char* directors[], int N, int K)
{
    const char** chosens = new const char*[K];
    backtrack(directors, N, K, chosens, 0, 0);
    delete[] chosens;
}

int main()
{
    const char* directors[5] = {"Tom", "John", "Rose", "ABC", "XYZ"};
    int N = 5, K = 3;
    generate(directors, N, K);

    return 0;
}