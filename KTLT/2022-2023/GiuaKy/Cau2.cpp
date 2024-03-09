#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char* CIRCLES_FILE = "circles.bin";
const char* CUTS_FILE = "cuts.txt";

struct Circle
{
    int x;
    int y;
    int r; // radius
};

struct CirclePair
{
    Circle c1;
    Circle c2;
};

Circle* readCircles(int& size) {
    size = 0;

    FILE* pFile = fopen(CIRCLES_FILE, "rb");
    if (pFile == NULL) {
        printf("Error opening file %s", CIRCLES_FILE);
        return NULL;
    }

    fread(&size, sizeof(int), 1, pFile);
    Circle* circles = new Circle[size];
    fread(circles, sizeof(Circle), size, pFile);

    fclose(pFile);
    return circles;
}

bool isTouchingCircles(const Circle& c1, const Circle& c2) {
    int lower = (c1.r - c2.r);
    lower *= lower;

    int upper = (c1.r + c2.r);
    upper *= upper;

    int dx = (c1.x - c2.x);
    dx *= dx;

    int dy = (c1.y - c2.y);
    dy *= dy;

    int dist = dx + dy;

    return lower <= dist && dist <= upper;
}

CirclePair* getTouchingCircles(const Circle* circles, const int& size, int& nPairs) {
    nPairs = 0;
    for (int i = 0; i + 1 < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (isTouchingCircles(circles[i], circles[j])) {
                nPairs++;
            }
        }
    }

    if (nPairs == 0)
        return NULL;

    CirclePair* pairs = new CirclePair[nPairs];
    int idx = 0;
    for (int i = 0; i + 1 < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (isTouchingCircles(circles[i], circles[j])) {
                pairs[idx].c1 = circles[i];
                pairs[idx].c2 = circles[j];
                idx++;
            }
        }
    }

    return pairs;
}

void writeTouchingCircles(const CirclePair* pairs, const int& nPairs) {
    FILE* pFile = fopen(CUTS_FILE, "w");
    if (pFile == NULL) {
        printf("Error opening file %s", CUTS_FILE);
        return;
    }

    fprintf(pFile, "%d\n", nPairs);
    for (int i = 0; i < nPairs; i++) {
        Circle c1 = pairs[i].c1;
        Circle c2 = pairs[i].c2;
        fprintf(pFile, "%d %d %d %d %d %d\n", c1.x, c1.y, c1.r, c2.x, c2.y, c2.r);
    }

    fclose(pFile);
}

int main()
{
    int size = 0;
    Circle* circles = readCircles(size);

    int nPairs = 0;
    CirclePair* pairs = getTouchingCircles(circles, size, nPairs);

    writeTouchingCircles(pairs, nPairs);

    delete[] circles;
    delete[] pairs;

    return 0;
}