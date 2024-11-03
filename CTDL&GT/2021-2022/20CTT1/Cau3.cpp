#include <iostream>
using namespace std;

typedef struct Node* Ref;
struct Node
{
    Ref left;
    Ref right;
    int key;
};

Ref deleteNode(Ref root)
{
    if (root == nullptr)
        return root;

    if (root->left == nullptr)
        return root->right;

    if (root->right == nullptr)
        return root->left;

    // Có cả 2 con trái và phải
    // Chọn phần tử thay thế là lớn hơn gần nhất hoặc bé hơn gần nhất
    // Ở đây chọn lớn hơn gần nhất

    // Tìm phần tử nhỏ nhất ở cây con bên phải
    Ref p = root->right;
    Ref prev = nullptr;
    while (p->left != nullptr) {
        prev = p;
        p = p->left;
    }

    p->left = root->left;
    if (prev != nullptr) {
        prev->left = p->right;
        p->right = root->right;
    }

    return p;
}

void searchDel(Ref& root, int k)
{
    if (root == nullptr)
        return;

    Ref p = root;
    Ref prev = nullptr;
    while (p != nullptr && p->key != k) {
        prev = p;
        if (p->key < k)
            p = p->right;
        else
            p = p->left;
    }

    if (prev == nullptr)
        root = deleteNode(root); // Xóa node gốc và gán node gốc mới
    else if (prev->left == p)
        prev->left = deleteNode(p); // Trỏ prev->left sang node gốc mới
    else // prev->right == p
        prev->right = deleteNode(p); // Trỏ prev->right sang node gốc mới

    delete p;
}

int main()
{
    return 0;
}