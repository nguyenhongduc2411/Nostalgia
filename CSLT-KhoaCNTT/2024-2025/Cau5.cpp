#include <stdio.h>
#include <string.h>

struct Product
{
    char id[10];
    char name[100];
    long long price;
};

void findProducts(char* filePath, char* keyword)
{
    FILE* pFile = fopen(filePath, "rt");
    if (!pFile) {
        printf("Error opening file %s", filePath);
        return;
    }

    char buffer[100];
    while (fscanf(pFile, "%[^\n]\n", buffer) == 1) {
        Product p;
        sscanf(buffer, "%[^,],%[^,],%lld", p.id, p.name, &p.price);

        if (strstr(p.name, keyword)) {
            printf("%s;;%s;;%lld\n", p.id, p.name, p.price);
        }
    }
    fclose(pFile); // Important!!!
}

int main()
{
    char* filePath = "sanpham.txt";
    char* keyword = "samsung";
    findProducts(filePath, keyword);
}