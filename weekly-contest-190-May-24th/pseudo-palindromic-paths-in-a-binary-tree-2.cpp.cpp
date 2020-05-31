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
        int res = 0;

        auto countBit = [](int val) {
            int cnt = 0;
            while (val) {
                // printf("%x\n", val);
                cnt++;
                val &= val - 1;
            }
            return cnt;
        };

        function<void(TreeNode*, int)> countPath = [&](TreeNode* root, int mask) {
            if (!root)
                return;
            mask ^= 1 << (root->val);
            if (!root->left && !root->right) {
                if (countBit(mask) <= 1)
                    res++;
            } else {
                countPath(root->left, mask);
                countPath(root->right, mask);
            }
        };
        countPath(root, 0);
        return res;
    }
};
