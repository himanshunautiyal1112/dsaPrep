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
    int height(TreeNode* root, bool &valid) {
        if(!root)
        return 0;

        int l = height(root->left, valid);


        if(valid) {
            int r = height(root->right, valid);
            if(abs(l-r) > 1)
            valid = 0;

            return 1+max(l, r);
        }

        return -1;
    }
    bool isBalanced(TreeNode* root) {
        bool valid = true;

        height(root, valid);

        return valid;
    }
};