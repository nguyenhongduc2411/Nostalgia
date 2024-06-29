#include <iostream>
#include <string.h>
using namespace std;

struct SinhVien
{
    char ten[100];
    double DTB;
};

struct DSSV
{
    SinhVien DS[100];
    int nDS;  
};

struct SinhVien1
{
    char* ten;
    double DTB;
};

struct DSSV1
{
    SinhVien1* DS;
    int nDS;
};

void Free(DSSV1& ds1)
{
    for (int i = 0; i < ds1.nDS; i++) {
        delete[] ds1.DS[i].ten;
        ds1.DS[i].ten = nullptr;
    }
    delete[] ds1.DS;
    ds1.DS = nullptr;
    ds1.nDS = 0;
}

void TransferAndCopy(DSSV1& ds1, DSSV ds)
{
    // Mang tính chất an toàn
    if (ds1.DS != nullptr)
        Free(ds1);

    // Mang tính chất an toàn
    if (ds.nDS <= 0)
        return;

    ds1.nDS = ds.nDS;
    ds1.DS = new SinhVien1[ds1.nDS];

    for (int i = 0; i < ds1.nDS; i++) {
        SinhVien1 sv1;
        sv1.DTB = ds.DS[i].DTB;

        int len = strlen(ds.DS[i].ten);
        sv1.ten = new char[len + 1];
        strcpy(sv1.ten, ds.DS[i].ten);

        ds1.DS[i] = sv1;
    }
}

int main()
{
    DSSV ds;
    cin >> ds.nDS;
    for (int i = 0; i < ds.nDS; i++) {
        cin >> ds.DS[i].ten;
        cin >> ds.DS[i].DTB;
    }

    DSSV1 ds1;
    ds1.nDS = 0;
    ds1.DS = nullptr;
    TransferAndCopy(ds1, ds);

    cout << "After copy:\n";
    for (int i = 0; i < ds1.nDS; i++) {
        cout << ds1.DS[i].ten << " " << ds1.DS[i].DTB << "\n";
    }

    Free(ds1);

    return 0;
}