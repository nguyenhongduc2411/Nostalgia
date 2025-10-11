/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findMaxSum(Node *root) {
        int ans = INT_MIN;
        auto dfs = [&](auto&& dfs, Node* u) -> int {
            if (!u)
                return 0;
                
            int left = dfs(dfs, u->left);
            int right = dfs(dfs, u->right);
            left = max(0, left);
            right = max(0, right);
            
            ans = max(ans, u->data + left + right);
            return max(u->data + left, u->data + right);
        };
        dfs(dfs, root);
        return ans;
    }
};