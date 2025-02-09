#include <iostream>
#include <vector>
using namespace std;

typedef struct Node* Ref;
struct Node
{
    Ref left;
    Ref right;
    int key;
};

/*

Duyệt in-order trên cây nhị phân tìm kiếm sẽ cho ta các số theo thứ tự tăng dần
Duyệt LNR

*/

void traverse(Ref r, vector<int>& nodes)
{
    if (r == nullptr)
        return;

    traverse(r->left, nodes);
    nodes.push_back(r->key);
    traverse(r->right, nodes);
}

bool isEquivalent(Ref r1, Ref r2)
{
    vector<int> arr1, arr2;
    traverse(r1, arr1);
    traverse(r2, arr2);

    // Kích thước 2 cây khác nhau
    if (arr1.size() != arr2.size())
        return false;

    for (int i = 0; i < arr1.size(); i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main()
{
    return 0;
}