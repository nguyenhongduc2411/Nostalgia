#include <stdio.h>
#include <stdlib.h> // Test
#include <time.h> // Test

/*
int: 4 byte
short: 2 byte
*/

const char* MATRIX_FILE = "matrix.bin";
const char* DIAG_FILE = "diag.in";

// Test
void writeMatrix()
{
    FILE* pFile = fopen(MATRIX_FILE, "wb");
    if (pFile == NULL) {
        printf("Error opening file %s", MATRIX_FILE);
        return;
    }

    const int m = 5;
    fwrite(&m, sizeof(int), 1, pFile);

    printf("writeMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            short element = i * m + j;
            // short element = rand(); // Test
            fwrite(&element, sizeof(short), 1, pFile);
            printf("%d ", element);
        }
        printf("\n");
    }

    fclose(pFile);
}

short** readMatrix(int& m)
{
    m = 0;

    FILE* pFile = fopen(MATRIX_FILE, "rb");
    if (pFile == NULL) {
        printf("Error opening file %s", MATRIX_FILE);
        return NULL;
    }

    fread(&m, sizeof(int), 1, pFile);
    short** matrix = new short*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new short[m];
    }

    // fread(matrix, sizeof(short), m * m, pFile); // Sai nếu là mảng cấp phát động

    for (int i = 0; i < m; i++) {
        fread(matrix[i], sizeof(short), m, pFile);
    }

    printf("readMatrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(pFile);
    return matrix;
}

void writeDiag(short** matrix, const int& m)
{
    FILE* pFile = fopen(DIAG_FILE, "wb");
    if (pFile == NULL) {
        printf("Error opening file %s", DIAG_FILE);
        return;
    }

    fwrite(&m, sizeof(int), 1, pFile);

    printf("writeDiag:\n");

    // Đường chéo chính
    for (int i = 0; i < m; i++) {
        fwrite(&matrix[i][i], sizeof(short), 1, pFile);
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    // Đường chéo phụ
    for (int i = m - 1; i >= 0; i--) {
        fwrite(&matrix[i][m - i - 1], sizeof(short), 1, pFile);
        printf("%d ", matrix[i][m - i - 1]);
    }
    printf("\n");

    fclose(pFile);
}

int main()
{
    srand(time(NULL));

    writeMatrix();

    int m;
    short** matrix = readMatrix(m);

    writeDiag(matrix, m);

    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}