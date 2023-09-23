#include <stdio.h>
#include <string.h>

/*

Hom
012

1 - 0 = 1

0 - -2 = 2 > 1

H o
2 - 0 = 2 > 1

*/

int countWords(const char str[])
{
    const char SEPARATORS[] = " ,.";
    const int N_SEPARATORS = strlen(SEPARATORS);

    int n = strlen(str);

    int count = 0;
    int lastLetterIdx = -2;
    for (int i = 0; i < n; i++) {
        int isLetter = 1;
        for (int j = 0; j < N_SEPARATORS; j++) {
            if (str[i] == SEPARATORS[j]) {
                isLetter = 0;
                break;
            }
        }

        if (isLetter) {
            if (i - lastLetterIdx > 1) {
                count++;
            }
            lastLetterIdx = i;
        }
    }
    return count;
}

void normalizeStr(char str[])
{
    int n = strlen(str);

    int firstLetterIdx = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] != ' ') {
            firstLetterIdx = i;
            break;
        }
    }

    int lastLetterIdx = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            lastLetterIdx = i;
            break;
        }
    }

    int currentIdx = 0;
    for (int i = firstLetterIdx; i <= lastLetterIdx; i++) {
        if (str[i] != ' ') {
            str[currentIdx] = str[i];
            currentIdx++;
        }
        else { // str[i] == ' '
            if (i + 1 < n && str[i + 1] != ' ') {
                str[currentIdx] = ' ';
                currentIdx++;
            }
        }
    }
    str[currentIdx] = '\0';
}

int main()
{
    char str[] = "   Hom nay,troi   dep qua.Hay  ra ngoai choi  ";
    printf("%d\n", countWords(str));

    normalizeStr(str);
    printf("%s\n", str);
    printf("%d\n", strlen(str));

    char str2[] = "Hom nay,troi dep qua.Hay ra ngoai choi";
    printf("%d\n", strlen(str2));

    return 0;
}