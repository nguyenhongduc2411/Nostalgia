#include <stdio.h>

/*
y = a * x + b

y1 = a * x1 + b
y2 = a * x2 + b

a1 * x1 - a * x2 = y1 - y2
a1 * (x1 - x2) = y1 - y2
a1 = (y1 - y2) / (x1 - x2) (a là hệ số góc của đường thẳng)

y3 = a * x3 + b
a2 = (y1 - y3) / (x1 - x3)

a1 == a2 -> Thẳng hàng
(y1 - y2) / (x1 - x2) == (y1 - y3) / (x1 - x3)
(y1 - y2) * (x1 - x3) = (y1 - y3) * (x1 - x2)

*/

const char* DIAG_FILE = "diag.in";
const char* LINE_FILE = "line.txt";

struct Point
{
    short x;
    short y;  
};

Point* readPoints(int& m)
{
    m = 0;

    FILE* pFile = fopen(DIAG_FILE, "rb");
    if (pFile == NULL) {
        printf("Error opening file %s", DIAG_FILE);
        return NULL;
    }

    fread(&m, sizeof(int), 1, pFile);
    Point* points = new Point[m];

    for (int i = 0; i < m; i++) {
        fread(&points[i].x, sizeof(short), 1, pFile);
    }

    for (int i = 0; i < m; i++) {
        fread(&points[i].y, sizeof(short), 1, pFile);
    }

    printf("readPoints:\n");
    for (int i = 0; i < m; i++) {
        printf("(%d, %d) ", points[i].x, points[i].y);
    }
    printf("\n");

    fclose(pFile);
    return points;
}

bool isCollinear(const Point& p1, const Point& p2, const Point& p3)
{
    // (y1 - y2) * (x1 - x3) = (y1 - y3) * (x1 - x2)
    int a1 = (p1.y - p2.y) * (p1.x - p3.x);
    int a2 = (p1.y - p3.y) * (p1.x - p2.x);
    return a1 == a2;
}

Point* find3CollinearPoints(Point* points, const int& m)
{
    for (int i = 0; i + 2 < m; i++) {
        for (int j = i + 1; j + 1 < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (isCollinear(points[i], points[j], points[k])) {
                    Point* result = new Point[3];
                    result[0] = points[i];
                    result[1] = points[j];
                    result[2] = points[k];
                    return result;
                }
            }
        }
    }

    return NULL;
}

void write3CollinearPoints(Point* points)
{
    FILE* pFile = fopen(LINE_FILE, "wt");
    if (pFile == NULL) {
        printf("Error opening file %s", LINE_FILE);
        return;
    }

    if (points == NULL) {
        fprintf(pFile, "%d", 0);
    }
    else {
        fprintf(pFile, "%d\n", 1);
        for (int i = 0; i < 3; i++) {
            fprintf(pFile, "%d %d", points[i].x, points[i].y);
            if (i < 2)
                fprintf(pFile, "\n");
        }
    }

    fclose(pFile);
}

int main()
{
    int m;
    Point* points = readPoints(m);

    Point* result = find3CollinearPoints(points, m);

    write3CollinearPoints(result);

    delete[] points;
    delete[] result;

    return 0;
}