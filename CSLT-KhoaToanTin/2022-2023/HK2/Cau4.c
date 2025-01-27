#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* replicateStr(char* str, int n)
{
    int length = strlen(str);

    int resultLength = length * n;
    char* result = (char*)malloc(resultLength + 1);
    result[resultLength] = '\0';

    for (int i = 0; i < resultLength; i++) {
        int j = i % length;
        result[i] = str[j];
    }

    return result;
}

int main()
{
    char* str = "ABCD";

    char* result = replicateStr(str, 5);
    printf("%s", result);

    free(result);

    return 0;
}