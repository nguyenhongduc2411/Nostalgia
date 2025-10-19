/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    void transformTree(Node *root) {
        int sum = 0;
        // Reverse in-order
        auto traverse = [&](auto&& self, Node* u) -> void {
            if (!u)
                return;
                
            self(self, u->right);
            
            int temp = u->data;
            u->data = sum;
            sum += temp;
            
            self(self, u->left);
        };
        traverse(traverse, root);
    }
};