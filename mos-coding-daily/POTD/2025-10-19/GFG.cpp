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
    vector<int> getKClosest(Node* root, int target, int k) {
        priority_queue<pair<int, int>> pq;
        auto dfs = [&](auto&& dfs, Node* u) -> void {
            if (!u)
                return;
                
            int diff = abs(target - u->data);
            pq.push({diff, u->data});
            if (pq.size() > k) {
                pq.pop();
            }
            
            dfs(dfs, u->left);
            dfs(dfs, u->right);
        };
        dfs(dfs, root);
        
        vector<int> ans;
        while (!pq.empty()) {
            auto [diff, v] = pq.top();
            pq.pop();
            ans.push_back(v);
        }
        return ans;
    }
};