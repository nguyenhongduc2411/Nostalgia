/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // Xử lý từ node lá trở lên thì sẽ không bị vấn đề ảnh hưởng tới các node con
        auto dfs = [&](auto&& dfs, Node* u) -> Node* {
            if (!u)
                return nullptr;
                
            if (u->data < l) {
                return dfs(dfs, u->right);
            }
            if (u->data > r) {
                return dfs(dfs, u->left);
            }
            
            u->left = dfs(dfs, u->left);
            u->right = dfs(dfs, u->right);
            return u;
        };
        return dfs(dfs, root);
    }
};