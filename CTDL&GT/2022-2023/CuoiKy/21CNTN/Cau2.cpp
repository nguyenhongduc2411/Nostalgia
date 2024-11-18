#include <iostream>
using namespace std;

typedef struct Node* Ref;
struct Node
{
    Ref left;
    Ref right;
    int key;
    int items; // Tổng số node của cây con có gốc là node này
};

int countNodes(Ref root)
{
    int cnt = 0;
    Ref cur = root;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            cnt++;
            cur = cur->right;
        }
        // cur->left != nullptr: Có cây con bên trái
        else {
            Node* pre = cur->left;
            while (pre->right != nullptr && pre->right != cur) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                pre->right = cur;
                cur = cur->left;
            }
            else if (pre->right == cur) {
                pre->right = nullptr;
                cnt++;
                cur = cur->right;
            }
        }
    }
    return cnt;
}

Ref getNode(Ref root, int target)
{
    int cnt = 0;
    Ref cur = root;
    Ref node = nullptr;
    while (cur != nullptr) {
        if (cur->left == nullptr) {
            cnt++;
            if (cnt == target)
                node = cur;
            cur = cur->right;
        }
        // cur->left != nullptr: Có cây con bên trái
        else {
            Node* pre = cur->left;
            while (pre->right != nullptr && pre->right != cur) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                pre->right = cur;
                cur = cur->left;
            }
            else if (pre->right == cur) {
                pre->right = nullptr;
                cnt++;
                if (cnt == target)
                    node = cur;
                cur = cur->right;
            }
        }
    }
    return node;
}

// O(n)
int timtrungvi(Ref root)
{
    if (root == nullptr)
        return -1;

    int n = countNodes(root);
    Ref node = getNode(root, (n + 1) / 2);
    return node->key;
}

// O(h) với h là chiều cao của cây
int timtrungvihieuqua(Ref root)
{
    if (root == nullptr)
        return -1;

    int n = root->items;
    int k = (n + 1) / 2;
    Ref cur = root;
    while (true) {
        int left = 1 + (cur->left != nullptr ? cur->left->items : 0);
        if (k == left) {
            return cur->key;
        }

        if (k < left) {
            cur = cur->left;
        }
        else {
            k -= left;
            cur = cur->right;
        }
    }
}

int main()
{
    return 0;
}