/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool left = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while (size--) {
                Node* u = q.front();
                q.pop();
                temp.push_back(u->data);
                if (u->left) {
                    q.push(u->left);
                }
                if (u->right) {
                    q.push(u->right);
                }
            }
            if (!left)
                reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
            left = !left;
        }
        return ans;
    }
};