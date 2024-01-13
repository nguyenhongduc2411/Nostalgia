#include <stdio.h>
#include <string.h>

struct Package
{
    char id[18];
    char receiver[16];
    char address[51];
    char phone[11];
    double weight;
};

void readPackages(Package packages[], int& size)
{
    size = 0;

    FILE* pFile = fopen("input.txt", "r");
    if (pFile == NULL)
        return;

    const int MAX = 200;
    char line[MAX];
    bool isFirstLine = true;

    while (fgets(line, MAX, pFile) != NULL) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        Package p;
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%lf", p.id, p.receiver, p.address, p.phone, &p.weight);

        packages[size] = p;
        size++;
    }

    fclose(pFile);
}

void writePackages(Package packages[], int size, char deliveryDist[])
{
    FILE* pFile = fopen("output.txt", "w");
    if (pFile == NULL)
        return;

    fputs("Ma don hang|Ten nguoi nhan|Dia chi|So dien thoai|Khoi luong\n", pFile);

    for (int i = 0; i < size; i++) {
        Package p = packages[i];
        char* address = p.address;

        char temp[51];
        char district[51];
        sscanf(address, "%[^,], %[^,], %[^,], %[^,]", temp, temp, temp, district);

        if (strcmp(district, deliveryDist) == 0) {
            fprintf(pFile, "%s|%s|%s|%s|%.1lf\n", p.id, p.receiver, p.address, p.phone, p.weight);
        }
    }

    fclose(pFile);
}

int main()
{
    const int MAX = 100;
    Package packages[MAX];

    int size;
    readPackages(packages, size);

    char deliveryDist[] = "Q12";
    writePackages(packages, size, deliveryDist);

    return 0;
}