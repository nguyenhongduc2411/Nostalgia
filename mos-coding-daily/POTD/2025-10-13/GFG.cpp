/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

/*

pair<int, int>
pair.first: Có lấy phần tử hiện tại
pair.second: Không lấy phần tử hiện tại

*/

class Solution {
  public:
    int getMaxSum(Node *root) {
        auto dfs = [&](auto&& dfs, Node* u) -> pair<int, int> {
            if (!u)
                return {0, 0};
                
            pair<int, int> left = dfs(dfs, u->left);
            pair<int, int> right = dfs(dfs, u->right);
            
            int first = u->data + left.second + right.second;
            int second = max(left.first, left.second) + max(right.first, right.second);
            
            return {first, second};
        };
        pair<int, int> ans = dfs(dfs, root);
        return max(ans.first, ans.second);
    }
};