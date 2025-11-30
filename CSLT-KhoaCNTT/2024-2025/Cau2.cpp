#include <stdio.h>
#include <iostream>
using namespace std;

int findPartitionIndex(int* nums, int size)
{
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += nums[i];
    }
    int sum = 0;
    for (int i = 0; i + 1 < size; i++) {
        sum += nums[i];
        if (sum == total - sum) {
            return i;
        }
    }
    return -1;
}

int main()
{
    {
        int nums[] = {1, 1, 1, 2, 1};
        int size = sizeof(nums) / sizeof(*nums);
        cout << findPartitionIndex(nums, size) << "\n";
    }

    {
        int nums[] = {2, 1, 1, 2, 1};
        int size = sizeof(nums) / sizeof(*nums);
        cout << findPartitionIndex(nums, size) << "\n";
    }

    {
        int nums[] = {10, 10};
        int size = sizeof(nums) / sizeof(*nums);
        cout << findPartitionIndex(nums, size) << "\n";
    }

    return 0;
}