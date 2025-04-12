#include <iostream>
using namespace std;

struct Node
{
    char value;
    Node *pLeft, *pRight;
};

bool isConsonant(char c)
{
    static char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    for (char v : vowels) {
        if (v == c)
            return false;
    }
    return true;
}

int traverse(Node *pRoot, int& ans)
{
    if (pRoot == nullptr)
        return 0;

    int cnt = isConsonant(pRoot->value);
    int left = traverse(pRoot->pLeft, ans);
    int right = traverse(pRoot->pRight, ans);

    // Số phụ âm ở cây con bên trái lớn hơn cây con bên phải
    if (left > right)
        ans++;

    return cnt + left + right;
}

int countConsonant(Node *pRoot)
{
    int ans = 0;
    traverse(pRoot, ans);
    return ans;
}

int main()
{
    return 0;
}