/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        auto dfs = [&](auto&& dfs, Node* u) -> int {
            if (!u)
                return 0;
                
            if (u->data < l) {
                return dfs(dfs, u->right);
            }
            if (u->data > r) {
                return dfs(dfs, u->left);
            }
            
            return u->data + dfs(dfs, u->left) + dfs(dfs, u->right);
        };
        return dfs(dfs, root);
    }
};
