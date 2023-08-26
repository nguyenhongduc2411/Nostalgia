#include <iostream>
#include <string.h>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

// aaa*bbb*ccc*ddd*eee
// => ["bbb", "ccc", "ddd"]

// *aaa*bbb*ccc*ddd*eee
// => ["aaa", "bbb", "ccc", "ddd"]


// aaa*bbb*ccc*ddd*eee*
// => ["bbb", "ccc", "ddd", "eee"]

void getTokens(const char s[], char tokens[][MAX_SIZE], int& count)
{
    int length = strlen(s);
    int start = 0;
    bool isFirstFound = false;
    while (start < length) {
        const char* pos = strchr(s + start, '*');
        if (pos == NULL)
            break;

        int tokenLength = pos - (s + start);
        if (start == 0){
            start = start + tokenLength + 1;
            continue;
        }

        strncpy(tokens[count], s + start, tokenLength);
        tokens[count][tokenLength] = '\0';

        start = start + tokenLength + 1;
        count++;
    }
}

int strmatch(const char s[], const char t[])
{
    int sLength = strlen(s);
    int tLength = strlen(t);

    if (strchr(s, '*') == NULL) {
        return strcmp(s, t) == 0;
    }

    int posFirstStar;
    for (int i = 0; i < sLength; i++) {
        if (s[i] == '*') {
            posFirstStar = i;
            break;
        }

        if (s[i] != t[i])
            return 0;
    }

    for (int i = sLength - 1, j = tLength - 1; i >= 0 && j >= 0; i--, j--) {
        if (s[i] == '*')
            break;

        if (s[i] != t[j])
            return 0;
    }

    char tokens[MAX_SIZE][MAX_SIZE];
    int count = 0;
    getTokens(s, tokens, count);

    int start = posFirstStar;
    for (int i = 0; i < count; i++) {
        const char* current = strstr(t + start, tokens[i]);
        if (current == NULL)
            return 0;

        start += strlen(tokens[i]);
    }

    return 1;
}

int main()
{
    cout << "TRUE\n";

    string s = "app*";
    string t = "apple";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "*aaa*bbb*ccc*ddd*eee*";
    t = "aaaAAAbbbBBBcccCCCdddDDDeee";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "*ion";
    t = "lion";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "the*quick*fox";
    t = "the-quickfox";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "the*quick*fox";
    t = "the very quick brown fox";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    cout << "\nFALSE\n";

    s = "alp*";
    t = "apple";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "*ion";
    t = "lionee";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    s = "the*quick*fox";
    t = " the-quickfox";
    cout << strmatch(s.c_str(), t.c_str()) << "\n";

    return 0;
}