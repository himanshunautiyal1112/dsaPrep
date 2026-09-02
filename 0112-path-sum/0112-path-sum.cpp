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
    bool pp(TreeNode* root, int target, int sum) {
        if(!root)
        return 0;

        if(!root->left && !root->right) {
            return sum + root->val == target ? 1: 0;
        }

       return pp(root->left, target, sum+root->val) ||
        pp(root->right, target, sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return pp(root, targetSum, sum);
    }
};