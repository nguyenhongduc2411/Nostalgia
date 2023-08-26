#include <iostream>
using namespace std;

void printSecondLargest(int a, int b, int c)
{
    int arr[] = {a, b, c};
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    if (arr[1] < arr[2]) {
        cout << arr[1];
    }
    else if (arr[0] < arr[2]) {
        cout << arr[0];
    }
    else {
        cout << "Khong co so lon nhi.";
    }
}

int main()
{
    printSecondLargest(5, 5, 5);
    return 0;
}