#include <iostream>
using namespace std;

typedef struct Node* Ref;
struct Node
{
    Ref left;
    Ref right;
    int key;
};

// Không được tạo mảng các khóa rồi sort
// Ý tưởng là chỉ di chuyển con trỏ
// Có thể hình dung là tạo nên cây BST mới từ cây BT ban đầu

void insertBST(Ref& root, Ref node)
{
    if (!root) {
        root = node;
        root->left = root->right = nullptr;
        return;
    }

    if (node->key < root->key) {
        insertBST(root->left, node);
    }
    else {
        insertBST(root->right, node);
    }
}

void traverse(Ref& newRoot, Ref node)
{
    if (!node)
        return;

    traverse(newRoot, node->left);
    traverse(newRoot, node->right);
    insertBST(newRoot, node);
}

// O(n^2)
void convertTree(Ref& root)
{
    Ref newRoot = nullptr;
    traverse(newRoot, root);
    root = newRoot;
}

int main()
{
    return 0;
}