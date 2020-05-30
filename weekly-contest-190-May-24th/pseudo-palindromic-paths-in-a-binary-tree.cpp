/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        unordered_set<int> oddsets;

        auto print = [](unordered_set<int> s) {
            cout<<"{";
            for(auto i : s){
                cout<<i;
            }
            cout<<"}";
        };

        auto addToSet = [&oddsets](int val) {
            if (oddsets.find(val) == oddsets.end()) {
                oddsets.insert(val);
            } else {
                oddsets.erase(val);
            }
        };

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root){
                return;
            }
            addToSet(root->val);
            if (root->left || root->right) {
                dfs(root->left);
                dfs(root->right);
            } else {
                cout<<"leaf";
                print(oddsets);
                if (oddsets.size() <= 1) {
                    cnt++;
                }
            }
            // remove cuurent leaf node from oddsets
            addToSet(root->val);
            // print(oddsets);
        };
        dfs(root);
        return cnt;
    }
};
