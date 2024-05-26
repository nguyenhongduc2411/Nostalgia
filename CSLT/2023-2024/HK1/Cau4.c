#include <stdio.h>

int demDayDongTri(int arr[], int n)
{
    int result = 0;
    int i = 0;
    while (i < n) {
        int count = 0;
        int current = arr[i];

        while (i < n && arr[i] == current) {
            i++;
            count++;
        }

        if (count >= 2)
            result++;
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(*arr);

    printf("%d", demDayDongTri(arr, n));

    return 0;
}