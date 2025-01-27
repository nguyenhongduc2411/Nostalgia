#include <stdio.h>
#include <string.h>

int findWrdChr(const char *str, char ch, int *pos)
{
    int size = strlen(str);
    int idx = 0;
    while (idx < size) {
        int start = idx;
        int len = 0;
        int hasChar = 0;
        while (idx < size && str[idx] != ' ') {
            if (str[idx] == ch)
                hasChar = 1;
            idx++;
            len++;
        }

        if (hasChar) {
            *pos = start;
            return len;
        }

        idx++;
    }

    *pos = -1;
    return 0;
}

int main()
{
    // {
    //     int len, pos;
    //     len = findWrdChr("Toan tin", 't', &pos);
    //     printf("%d %d\n", len, pos);
    // }

    // {
    //     int len, pos;
    //     len = findWrdChr("Toan tin", 'u', &pos);
    //     printf("%d %d\n", len, pos);
    // }

    char s[100];
    char c;
    scanf("%[^\n] %c", s, &c);

    int offset = 0;
    while (1) {
        int pos;
        int len = findWrdChr(s + offset, c, &pos);
        if (len == 0)
            break;

        offset += pos;
        printf("%d\t%d\n", offset, len);
        offset += len;
    }

    return 0;
}