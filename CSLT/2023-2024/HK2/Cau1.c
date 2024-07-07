#include <stdio.h>
#include <math.h>

double tinhKhoangCach(int x1, int y1, int x2, int y2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    int nPeople = 0;

    while (1) {
        int prev_x = 0, prev_y = 0;
        int x, y;
        int nStops = 0;
        double sum = 0;

        while (1) {
            scanf("%d %d", &x, &y);

            if (x == 0 || y == 0)
                break;

            if (prev_x != 0)
                sum += tinhKhoangCach(prev_x, prev_y, x, y);

            prev_x = x;
            prev_y = y;
            nStops++;
        }

        if (nStops > 0) {
            printf("So diem dung: %d\n", nStops);
            printf("Chieu dai hanh trinh: %.2lf\n", sum);
            nPeople++;
        }

        if (x == 0 && y == 0)
            break;
    }

    printf("Tong so nguoi di bo: %d\n", nPeople);

    return 0;
}