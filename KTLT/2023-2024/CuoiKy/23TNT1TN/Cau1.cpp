#include <iostream>
#include <string.h>
using namespace std;

/*

the, quick#!fox12
012

*/

bool isLetter(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;

    if (c >= 'A' && c <= 'Z')
        return true;

    return false;
}

void getWords(const char *S, char **&W, int &N)
{
    int len = strlen(S);
    N = 0;

    for (int i = 0; i < len; i++) {
        if (isLetter(S[i]) && (i + 1 == len || !isLetter(S[i + 1])))
            N++;
    }

    W = new char*[N];
    int idx = 0;
    int start = -1;

    for (int i = 0; i < len; i++) {
        if (!isLetter(S[i]))
            continue;

        if (start == -1)
            start = i;

        if (i + 1 == len || !isLetter(S[i + 1])) {
            int wordLen = i - start + 1;

            W[idx] = new char[wordLen + 1];
            strncpy(W[idx], S + start, wordLen);
            W[idx][wordLen] = '\0';

            idx++;
            start = -1;
        }
    }
}

int main()
{
    // const char* S = "the, quick#!fox";
    // const char* S = "123/456";
    const char* S = "the, quick#!fox12";

    char** W = nullptr;
    int N = 0;
    getWords(S, W, N);

    cout << "N: " << N << "\n";
    for (int i = 0; i < N; i++) {
        cout << W[i] << "(" << strlen(W[i]) << ")\n";
    }

    for (int i = 0; i < N; i++) {
        delete[] W[i];
    }
    delete[] W;

    return 0;
}