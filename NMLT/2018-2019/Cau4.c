#include <stdio.h>

typedef struct
{
    int left;
    int right;
    int bottom;
    int top;
} Rectangle;

/*

[2, 5]
[3, 4]
=> [3, 4]

[2, 4]
[3, 5]
=> [3, 4]

*/

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int calcIntersectArea(Rectangle r1, Rectangle r2)
{
    if (r2.left >= r1.right || r2.right <= r1.left)
        return 0;

    if (r2.bottom >= r1.top || r2.top <= r1.bottom)
        return 0;

    int left = max(r1.left, r2.left);
    int right = min(r1.right, r2.right);
    int width = right - left;
    // width = max(0, width);

    int bottom = max(r1.bottom, r2.bottom);
    int top = min(r1.top, r2.top);
    int height = top - bottom;
    // height = max(0, height);

    return width * height;
}

int main()
{
    Rectangle r1 = {1, 5, 1, 4};
    Rectangle r2 = {3, 6, 3, 5};
    printf("%d", calcIntersectArea(r1, r2));
    return 0;
}