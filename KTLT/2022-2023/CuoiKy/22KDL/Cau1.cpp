#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str[100];
    scanf("%[^\n]", str);

    int sum = 0;

    const char* delimeters = " Y=+";
    char* token = strtok(str, delimeters);
    while (token != NULL) {
        int num = atoi(token);

        int exp = num % 10;
        num /= 10;

        int cur = 1;
        for (int i = 1; i <= exp; i++) {
            cur *= num;
        }

        sum += cur;

        token = strtok(NULL, delimeters);
    }

    printf("%d", sum);

    return 0;
}