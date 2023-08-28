#include <iostream>
#include <string.h>
#include <string>
using namespace std;

/*
***Một quan sát thú vị***
Có 1 cách đơn giản hơn rất nhiều xDD Đó là:
- So sánh theo từng kí tự từ đầu của cả 2 chuỗi
- Nếu gặp kí tự nào khác nhau thì mình sẽ dừng so sánh và đếm số dấu '/' từ đó cho đến cuối chuỗi 1 và chuỗi 2
- Cộng số dấu '/' lại sẽ cho ta kết quả đúng
*/

const int MAX_SIZE = 100;

// ["/", "dirB", "dirC"]

// /dirB
// 012345

void getFolders(const char path[], char folders[][MAX_SIZE], int& count)
{
    const char SEPARATOR[] = "/";
    strcpy(folders[0], SEPARATOR);
    count++;

    int length = strlen(path);

    int start = 1;
    while (start < length) {
        const char* pos = strchr(path + start, '/');
        if (pos == NULL)
            break;

        int nameLength = pos - (path + start);
        strncpy(folders[count], path + start, nameLength);
        folders[count][nameLength] = '\0';

        start = start + nameLength + 1;
        count++;
    }
}

int calcDirDistance(const char f1[], const char f2[])
{
    char folders[MAX_SIZE][MAX_SIZE];
    int count1 = 0;
    getFolders(f1, folders, count1);

    char folders2[MAX_SIZE][MAX_SIZE];
    int count2 = 0;
    getFolders(f2, folders2, count2);
    
    // ["/", "dirB", "dirC"]

    for (int i = count1 - 1; i >= 0; i--) {
        if (i >= count2)
            continue;

        if (strcmp(folders[i], folders2[i]) == 0) {

            bool hasValidPath = true;
            for (int j = i - 1; j >= 0; j--) {
                if (strcmp(folders[j], folders2[j]) != 0) {
                    hasValidPath = false;
                    break;
                }
            }
            if (!hasValidPath)
                continue;

            int dist1 = count1 - i - 1;
            int dist2 = count2 - i - 1;
            return dist1 + dist2;
        } 
    }

    // for (int i = 0; i < count1; i++) {
    //     cout << folders[i] << "\n";
    // }
    // cout << "\n";
    // for (int i = 0; i < count2; i++) {
    //     cout << folders2[i] << "\n";
    // }

    return (count1 - 1) + (count2 - 1);
}

int main()
{
    string f1 = "/dirA/file1";
    string f2 = "/dirB/file2";
    string f3 = "/dirB/dirC/file3";
    string f4 = "/dirB/dirC/file4";

    string f5 = "/dirB/dirB/file5";
    string f6 = "/dirD/dirC/file6";

    cout << calcDirDistance(f4.c_str(), f3.c_str()) << "\n";
    cout << calcDirDistance(f4.c_str(), f2.c_str()) << "\n";
    cout << calcDirDistance(f4.c_str(), f1.c_str()) << "\n";
    cout << calcDirDistance(f2.c_str(), f1.c_str()) << "\n";

    cout << calcDirDistance(f5.c_str(), f4.c_str()) << "\n"; // 2
    cout << calcDirDistance(f6.c_str(), f4.c_str()) << "\n"; // 4

    return 0;
}