/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findMedian(Node* root) {
        int n = 0;
        auto dfs = [&](auto&& dfs, Node* u) -> void {
            if (!u)
                return;
                
            n++;
            dfs(dfs, u->left);
            dfs(dfs, u->right);
        };
        dfs(dfs, root);
        
        // n là số lượng node
        int cnt = 0;
        int ans;
        auto inorder = [&](auto&& inorder, Node* u) -> void {
            if (!u)
                return;
                
            inorder(inorder, u->left);
            
            if (++cnt == (n + 1) / 2) {
                ans = u->data;
            }

            inorder(inorder, u->right);
        };
        inorder(inorder, root);
        return ans;
    }
};