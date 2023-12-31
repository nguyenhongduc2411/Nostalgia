#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

long long fileSizeToDecimal(char fileSizeField[12])
{
    long long decimal = 0;
    long long factor = 1;

    for (int i = 10; i >= 0; i--) {
        if (fileSizeField[i]== '\0')
            break;

        int digit = fileSizeField[i] - '0';
        decimal += digit * factor;
        factor *= 8;
    }

    return decimal;
}

struct TarFile
{
    static const int BLOCK_SIZE = 512;

    static const int FILE_NAME_START = 0;
    static const int FILE_NAME_SIZE = 100;

    static const int FILE_SIZE_START = 124;
    static const int FILE_SIZE_SIZE = 12;

    char name[FILE_NAME_SIZE];
    long long size;

    bool read(ifstream& in)
    {
        char buffer[BLOCK_SIZE];
        in.read(buffer, BLOCK_SIZE);

        if (buffer[0] == '\0')
            return false;

        strncpy(name, buffer + FILE_NAME_START, FILE_NAME_SIZE);

        char fileSizeField[FILE_SIZE_SIZE];
        strncpy(fileSizeField, buffer + FILE_SIZE_START, FILE_SIZE_SIZE);

        size = fileSizeToDecimal(fileSizeField);

        // Skip data blocks (Cách tối ưu hơn)
        long long padding = (BLOCK_SIZE - size % BLOCK_SIZE) % BLOCK_SIZE;
        long long skippedSize = size + padding;
        in.seekg(skippedSize, in.cur);

        // Skip data blocks (Cách đơn giản)
        // long long current = 0;
        // while (current < size) {
        //     in.read(buffer, BLOCK_SIZE);
        //     current += BLOCK_SIZE;
        // }

        return true;
    }
};

void printFiles(const char* tarFile)
{
    ifstream in(tarFile, ios::in | ios::binary);

    // Check file is valid for reading
    if (!in) {
        cout << "Error opening \"" << tarFile << "\"";
        return;
    }

    TarFile file;
    while (file.read(in)) {
        cout << "Name: " << file.name << "; Size: " << file.size << "\n";
    }
}

int main()
{
    // char fileSizeField[] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '6', '5', '2', '\0' };
    // cout << fileSizeToDecimal(fileSizeField) << "\n";

    printFiles("sample-1.tar");

    return 0;
}