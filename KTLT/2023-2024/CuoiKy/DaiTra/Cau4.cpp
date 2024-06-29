#include <iostream>
#include <iomanip>
using namespace std;

struct Point
{
    int r;
    int c;
};

void findPath(int a[][100], int n, Point start, Point end, Point cur, int cnt, bool& found)
{
    a[cur.r][cur.c] = cnt;

    if (cur.r == end.r && cur.c == end.c) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(3) << a[i][j] << " ";
            }
            cout << "\n";
        }

        found = true;
        return;
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        Point next{cur.r + dr[i], cur.c + dc[i]};

        if (next.r < 0 || next.r >= n || next.c < 0 || next.c >= n)
            continue;

        if (a[next.r][next.c] != 0)
            continue;

        findPath(a, n, start, end, next, cnt + 1, found);
        if (found)
            return;
    }

    a[cur.r][cur.c] = 0;
}

int main()
{
    int a[][100] = {
        {-1, -1, -1, 0, -1, -1},
        {0, 0, 0, 0, -1, -1},
        {-1, -1, 0, 0, -1, 0},
        {0, 0, 0, -1, 0, 0},
        {-1, 0, -1, -1, -1, 0},
        {0, 0, 0, 0, 0, 0}
    };
    int n = 6;

    Point start{1, 0};
    Point end{3, 5};
    Point cur{start.r, start.c};
    int cnt = 1;
    bool found = false;

    findPath(a, n, start, end, cur, cnt, found);

    return 0;
}