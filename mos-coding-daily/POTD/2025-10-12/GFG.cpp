/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

// 1 1 1 1 1 1

// 2 2 2 0 0 0
// 1 1 1 1 1 1
// ans = 1 + 2 + 3 + 2 + 1

// 0 0 0 2 2 2
// 1 1 1
// abs(-1) + abs(-2) + abs(-3) + abs(-2) + abs(-1)

class Solution {
  public:
    int distCandy(Node* root) {
        int ans = 0;
        auto dfs = [&](auto&& dfs, Node* u) -> int {
            if (!u)
                return 0;
                
            int left = dfs(dfs, u->left);
            int right = dfs(dfs, u->right);
            
            int cur = left + right + u->data - 1;
            ans += abs(cur);
            return cur;
        };
        dfs(dfs, root);
        return ans;
    }
};