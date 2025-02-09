#include <iostream>
using namespace std;

typedef struct Node* Ref;
struct Node
{
    Ref left;
    Ref right;
    int key;
};

int findX(Ref r, int k)
{
    if (r == nullptr)
        return -1;

    Ref p = r;
    int minDiff = INT_MAX;
    int ans = -1;

    // O(log(n)) vì đây là cây AVL (Cây nhị phân tìm kiếm cân bằng)
    while (p != nullptr) {
        if (p->key == k)
            return p->key;

        int diff = abs(k - p->key);
        if (diff < minDiff) {
            minDiff = diff;
            ans = p->key;
        }

        if (p->key < k) {
            p = p->right;
        }
        else {
            p = p->left;
        }
    }

    return ans;
}

int main()
{
    return 0;
}