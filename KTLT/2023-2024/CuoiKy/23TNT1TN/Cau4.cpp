#include <stdio.h>
#include <iostream>
#include <string.h>
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
    long endOffset = ftell(pFile);

    uint16_t total;
    fseek(pFile, endOffset + 10, SEEK_SET);
    fread(&total, 2, 1, pFile);

    N = total;
    names = new char*[N];

    uint32_t centralOffset;
    fseek(pFile, endOffset + 16, SEEK_SET);
    fread(&centralOffset, 4, 1, pFile);

    fseek(pFile, centralOffset, SEEK_SET);
    for (int i = 0; i < N; i++) {
        long entryOffset = ftell(pFile);

        uint16_t nameLen;
        fseek(pFile, entryOffset + 28, SEEK_SET);
        fread(&nameLen, 2, 1, pFile);

        uint16_t extraLen;
        fseek(pFile, entryOffset + 30, SEEK_SET);
        fread(&extraLen, 2, 1, pFile);

        uint16_t commentLen;
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

// Nếu cần kiểm tra cả lúc đọc file có thành công hay không
// Thì sẽ xài hàm này và có try/catch ở trong hàm findFile
// (Tương tự sẽ cần có các hàm kiểm tra kết quả trả về của các hàm fread, ftell)
// int Fseek(FILE* pFile, long offset, int origin)
// {
//     if (fseek(pFile, offset, origin) != 0)
//         throw std::runtime_error("Error when fseek");
//     return 0;
// }

int findFile(const char *path, const char *name)
{
    FILE* pFile = fopen(path, "rb");
    if (pFile == NULL) {
        // cout << "Error opening file " << path << "\n";
        return -2;
    }

    fseek(pFile, -22, SEEK_END);
    long endOffset = ftell(pFile);

    uint16_t total;
    fseek(pFile, endOffset + 10, SEEK_SET);
    fread(&total, 2, 1, pFile);

    uint32_t centralOffset;
    fseek(pFile, endOffset + 16, SEEK_SET);
    fread(&centralOffset, 4, 1, pFile);

    fseek(pFile, centralOffset, SEEK_SET);
    for (int i = 0; i < total; i++) {
        long entryOffset = ftell(pFile);

        uint16_t nameLen;
        fseek(pFile, entryOffset + 28, SEEK_SET);
        fread(&nameLen, 2, 1, pFile);

        uint16_t extraLen;
        fseek(pFile, entryOffset + 30, SEEK_SET);
        fread(&extraLen, 2, 1, pFile);

        uint16_t commentLen;
        fseek(pFile, entryOffset + 32, SEEK_SET);
        fread(&commentLen, 2, 1, pFile);

        char* currentName = new char[nameLen + 1];
        currentName[nameLen] = '\0';
        fseek(pFile, entryOffset + 46, SEEK_SET);
        fread(currentName, 1, nameLen, pFile);

        if (strcmp(currentName, name) == 0) {
            delete[] currentName;
            fclose(pFile); // Important!!!
            return entryOffset;
        }
        delete[] currentName;

        fseek(pFile, entryOffset + 46 + nameLen + extraLen + commentLen, SEEK_SET);
    }

    fclose(pFile);
    return -1;
}

int main()
{
    char** names;
    int N;
    readZip("CLC.zip", names, N);

    for (int i = 0; i < N; i++) {
        cout << names[i] << "\n";
    }

    int result = findFile("CLC.zip", "CLC/Cau1.txt");
    cout << result;

    return 0;
}