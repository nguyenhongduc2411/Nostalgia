/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int kthSmallest(Node *root, int k) {
        int ans = -1;
        int cnt = 0;
        auto inorder = [&](auto&& self, Node* u) -> void {
            if (!u)
                return;
                
            self(self, u->left);
            if (++cnt == k) {
                ans = u->data;
            }
            self(self, u->right);
        };
        inorder(inorder, root);
        return ans;
    }
};