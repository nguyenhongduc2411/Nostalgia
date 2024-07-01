#include <iostream>
#include <string>
using namespace std;

/*

int: Thường là 4 bytes
short: Thường là 2 bytes

2 bytes: int16_t
4 bytes: int32_t

unsigned long long: 8 bytes không dấu

*/

struct BmpFileHeader
{
    int16_t signature;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t dataOffset;
};

struct BmpImageHeader
{
    uint32_t headerSize;
    int32_t wPixels;
    int32_t hPixels;
    uint16_t nColorPlanes;
    uint16_t bitsPerPixel;
    uint32_t compMethod;
    uint32_t imageSize;
    int32_t hResolution;
    int32_t vResolution;
    uint32_t nColors;
    uint32_t nImportantColors;
};

void readBmpFile(const char* fileName, BmpFileHeader& h1, BmpImageHeader& h2)
{
    FILE* pFile = fopen(fileName, "rb");
    if (pFile == NULL) {
        cout << "Error opening file " << fileName << "\n";
        return;
    }

    fread(&h1.signature,        2, 1, pFile);
    fread(&h1.fileSize,         4, 1, pFile);
    fread(&h1.reserved1,        2, 1, pFile);
    fread(&h1.reserved2,        2, 1, pFile);
    fread(&h1.dataOffset,       4, 1, pFile);

    fread(&h2.headerSize,       4, 1, pFile);
    fread(&h2.wPixels,          4, 1, pFile);
    fread(&h2.hPixels,          4, 1, pFile);
    fread(&h2.nColorPlanes,     2, 1, pFile);
    fread(&h2.bitsPerPixel,     2, 1, pFile);
    fread(&h2.compMethod,       4, 1, pFile);
    fread(&h2.imageSize,        4, 1, pFile);
    fread(&h2.hResolution,      4, 1, pFile);
    fread(&h2.vResolution,      4, 1, pFile);
    fread(&h2.nColors,          4, 1, pFile);
    fread(&h2.nImportantColors, 4, 1, pFile);

    fclose(pFile);
}

size_t computePaddingBytes(BmpImageHeader h)
{
    size_t imageSize = h.imageSize; // Bytes -> Nhân 8 để thành bits
    size_t rawSize = (size_t)h.wPixels * h.hPixels * h.bitsPerPixel; // Bits

    size_t paddingBits = (imageSize * 8 - rawSize);
    size_t paddingBytes = paddingBits / 8; // Làm tròn xuống

    // cout << "imageSize: " << imageSize << "\n";
    // cout << "imageSize * 8: " << imageSize * 8 << "\n";
    // cout << "rawSize: " << rawSize << "\n";
    // cout << "paddingBits: " << paddingBits << "\n";

    return paddingBytes;
}
int main()
{
    string fileName;
    // fileName = "2.bmp";
    getline(cin, fileName);

    BmpFileHeader h1;
    BmpImageHeader h2;
    readBmpFile(fileName.c_str(), h1, h2);

    size_t paddingBytes = computePaddingBytes(h2);
    cout << "paddingBytes: " << paddingBytes;

    return 0;
}