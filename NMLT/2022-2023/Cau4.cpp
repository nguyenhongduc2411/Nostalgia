#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int MAX_SIZE = 100;

struct Point
{
    double x;
    double y;

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

struct Triangle
{
    Point a;
    Point b;
    Point c;

    friend ostream& operator<<(ostream& out, const Triangle& t)
    {
        out << "Triangle: " << t.a << ", " << t.b << ", " << t.c;
        return out;
    }
};

struct Circle
{
    Point center;
    double radius;

    friend ostream& operator<<(ostream& out, const Circle& c)
    {
        out << "Circle: " << c.center << ", " << c.radius;
        return out;
    }
};

double readNumber(const char str[])
{
    double number;
    sscanf(str, "%lf", &number);
    return number;
}

Point readPoint(const char str[], int& next)
{
    Point p;

    const char* firstEnd = strchr(str, ',');
    p.x = readNumber(str + 1);
    p.y = readNumber(str + (firstEnd - str) + 2);

    const char* secondEnd = strchr(str + (firstEnd - str), ')');
    next += secondEnd - str;

    return p;
}

Triangle readTriangle(const char line[])
{
    Triangle t;

    int start = 4;
    t.a = readPoint(line + start, start);

    start += 3;
    t.b = readPoint(line + start, start);

    start += 3;
    t.c = readPoint(line + start, start);

    return t;
}

Circle readCircle(const char line[])
{
    Circle c;

    int start = 4;
    c.center = readPoint(line + start, start);

    start += 3;
    c.radius = readNumber(line + start);

    return c;
}

void read(Triangle tri[], int& n1, Circle cir[], int& n2) 
{
    ifstream input("SHAPES.TXT", fstream::in);

    char line[MAX_SIZE];

    while (input.getline(line, MAX_SIZE)) {
        if (line[1] == '0') {
            Triangle t = readTriangle(line);
            tri[n1] = t;
            n1++;
        }
        else {
            Circle c = readCircle(line);
            cir[n2] = c;
            n2++;
        }
    }
}

int main()
{
    Triangle tri[MAX_SIZE];
    int n1 = 0;

    Circle cir[MAX_SIZE];
    int n2 = 0;

    read(tri, n1, cir, n2);

    for (int i = 0; i < n1; i++) {
        cout << tri[i] << "\n";
    }

    for (int i = 0; i < n2; i++) {
        cout << cir[i] << "\n";
    }

    return 0;
}