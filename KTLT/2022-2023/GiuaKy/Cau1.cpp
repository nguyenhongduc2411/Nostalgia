#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* CIRCLES_FILE = "circles.bin";

struct Circle
{
    int x;
    int y;
    int r; // radius
};

int getRandomInt(int min)
{
    return rand() + min;
}

// [min, max)
int getRandomInt(int min, int max)
{
    return rand() % (max - min) + min;
}

int getRandomSize()
{
    return getRandomInt(101, 111);
}

Circle* getRandomCircles(int& size)
{
    size = getRandomSize();
    Circle* circles = new Circle[size];

    for (int i = 0; i < size; i++) {
        circles[i].x = getRandomInt(0);
        circles[i].y = getRandomInt(0);
        circles[i].r = getRandomInt(1);
    }

    return circles;
}

void writeCircles(const Circle* circles, const int& size)
{
    FILE* pFile = fopen(CIRCLES_FILE, "wb");
    if (pFile == NULL) {
        printf("Error opening file %s", CIRCLES_FILE);
        return;
    }

    fwrite(&size, sizeof(int), 1, pFile);
    fwrite(circles, sizeof(Circle), size, pFile);

    fclose(pFile);
}

int main()
{
    srand(time(NULL));

    int size = 0;
    Circle* circles = getRandomCircles(size);

    writeCircles(circles, size);

    delete[] circles;

    return 0;
}