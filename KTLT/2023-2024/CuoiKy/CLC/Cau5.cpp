#include <stdio.h>
#include <iostream>
using namespace std;

void readZip(const char* zipPath, char** &names, int& N)
{
    N = 0;

    FILE* pFile = fopen(zipPath, "rb");
    if (pFile == NULL) {
        cout << "Error opening file " << zipPath << "\n";
        return;
    }

    fseek(pFile, -22, SEEK_END);
    int endOffset = ftell(pFile);

    short total;
    fseek(pFile, endOffset + 10, SEEK_SET);
    fread(&total, 2, 1, pFile);

    N = total;
    names = new char*[N];

    int centralOffset;
    fseek(pFile, endOffset + 16, SEEK_SET);
    fread(&centralOffset, 4, 1, pFile);

    fseek(pFile, centralOffset, SEEK_SET);
    for (int i = 0; i < N; i++) {
        int entryOffset = ftell(pFile);

        short nameLen;
        fseek(pFile, entryOffset + 28, SEEK_SET);
        fread(&nameLen, 2, 1, pFile);

        short extraLen;
        fseek(pFile, entryOffset + 30, SEEK_SET);
        fread(&extraLen, 2, 1, pFile);

        short commentLen;
        fseek(pFile, entryOffset + 32, SEEK_SET);
        fread(&commentLen, 2, 1, pFile);

        names[i] = new char[nameLen + 1];
        names[i][nameLen] = '\0';
        fseek(pFile, entryOffset + 46, SEEK_SET);
        fread(names[i], 1, nameLen, pFile);

        fseek(pFile, entryOffset + 46 + nameLen + extraLen + commentLen, SEEK_SET);
    }

    fclose(pFile);
}

int main()
{
    char** names;
    int N;
    readZip("CLC.zip", names, N);

    for (int i = 0; i < N; i++) {
        cout << names[i] << "\n";
    }

    return 0;
}