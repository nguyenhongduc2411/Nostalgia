#include <stdio.h>
#include <math.h>

/*

5
1.0 2.3 4.1 5.6
10000
1 2
6
1.2 2.5 4.0 5.6 7.0
15000
0 3
0

*/

int main()
{
    double sum = 0;
    int cnt = 1;
    double dists[100] = {0};

    while (1) {
        printf("So tram cua tuyen thu %d: ", cnt);
        int nStops;
        scanf("%d", &nStops);
        if (nStops == 0)
            break;

        printf("Cu ly cua tuyen thu %d: ", cnt);
        dists[0] = 0;
        for (int i = 1; i < nStops; i++) {
            scanf("%lf", &dists[i]);
        }

        printf("Gia ve cua tuyen thu %d: ", cnt);
        double fee;
        scanf("%lf", &fee);

        printf("Vi tri tram khach len va xuong cua tuyen thu %d: ", cnt);
        int start, end;
        scanf("%d %d", &start, &end);

        double dist = fabs(dists[end] - dists[start]);
        double full_dist = dists[nStops - 1];
        double current_fee = 0;

        if (dist >= full_dist*3/4)
            current_fee = fee;
        else if (dist >= full_dist*1/2)
            current_fee = fee*0.75;
        else if (dist >= full_dist*1/4)
            current_fee = fee*0.5;
        else
            current_fee = fee*0.25;

        sum += current_fee; 
    }

    printf("So tien khach phai tra: %.2lf", sum);

    return 0;
}