#include <stdio.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

Point scanPoint()
{
    Point p;
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

void printPoint(const Point& p)
{
    printf("(%lf, %lf)", p.x, p.y);
}

double calcDistance(const Point& a, const Point& b)
{
    // sqrt((a.x - b.x)^2 + (a.y - b.y)^2)
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

Point translatePoint(const Point& a, double dx, double dy)
{
    Point b{a.x + dx, a.y + dy};
    return b;
}

void scanPoints(Point points[], int& n)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        points[i] = scanPoint();
    }
}

bool isPointLess(const Point& a, const Point& b)
{
    if (a.x != b.x)
        return a.x < b.x;

    return a.y < b.y;
}

void sortPoints(Point points[], int n)
{
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPointLess(points[j], points[i])) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

void printPoints(const Point points[], int n)
{
    for (int i = 0; i < n; i++) {
        printPoint(points[i]);
        printf("\n");
    }
}

int main()
{
    // Point a = scanPoint();
    // printPoint(a);
    // printf("\n");

    // Point b = scanPoint();
    // printPoint(b);
    // printf("\n");

    // double distance = calcDistance(a, b);
    // printf("Distance: %lf\n", distance);

    // a = translatePoint(a, 1, 1);
    // printf("Translate a: ");
    // printPoint(a);
    // printf("\n");

    // distance = calcDistance(a, b);
    // printf("Distance: %lf\n", distance);

    Point points[100];
    int n;
    
    scanPoints(points, n);
    sortPoints(points, n);
    printPoints(points, n);

    return 0;
}