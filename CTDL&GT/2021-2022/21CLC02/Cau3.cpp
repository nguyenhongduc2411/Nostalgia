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

void findLongestPath(Ref r, vector<int>& path, vector<int>& best)
{
    if (r == nullptr)
        return;

    path.push_back(r->key);

    if (path.size() > best.size())
        best = path;

    findLongestPath(r->left, path, best);
    findLongestPath(r->right, path, best);

    path.pop_back();
}

void printLongestPath(Ref r)
{
    vector<int> path;
    vector<int> best;
    findLongestPath(r, path, best);

    for (int u : best)
        cout << u << " ";
    cout << "\n";
}

Ref createNode(int key)
{
    Ref node = new Node{nullptr, nullptr, key};
    return node;
}

void deleteTree(Ref& r)
{
    if (r == nullptr)
        return;

    deleteTree(r->left);
    deleteTree(r->right);
    delete r;
    r = nullptr;
}

int main()
{
    Ref root = createNode(1);
    Ref child1 = createNode(2);
    Ref child2 = createNode(3);
    Ref child3 = createNode(4);
    root->left = child1;
    root->right = child2;
    child1->right = child3;

    printLongestPath(root);

    deleteTree(root);

    return 0;
}