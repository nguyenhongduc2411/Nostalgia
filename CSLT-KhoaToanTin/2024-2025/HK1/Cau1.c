#include <stdio.h>

int hasFailingGrade(double toan, double van, double ngoaingu)
{
    return toan == 0 || van == 0 || ngoaingu == 0;
}

int main()
{
    while (1) {
        double toan, van, ngoaingu;
        printf("Nhap diem khao sat: ");
        scanf("%lf %lf %lf", &toan, &van, &ngoaingu);

        if (toan < 0 || van < 0 || ngoaingu < 0) {
            printf("Tam biet. Hen gap lai.\n");
            break;
        }

        double tong = toan + van + ngoaingu;
        printf("Tong diem: %.1lf\n", tong);

        if (hasFailingGrade(toan, van, ngoaingu)) {
            printf("Bi diem liet. Can co gang.\n");
            continue;
        }

        while (1) {
            double diemchuan;
            printf("Nhap diem chuan trung binh: ");
            scanf("%lf", &diemchuan);

            if (diemchuan < 0)
                break;

            if (tong >= diemchuan + 0.5) {
                printf("Co kha nang trung tuyen.\n");
            }
            else {
                printf("Khong co kha nang trung tuyen.\n");
            }
        }
    }

    return 0;
}