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
    int findMaxPath(TreeNode* root, int &maxSum) {
        if(!root)
        return 0;

        // if(!root->left && !root->right)
        // return root->val;

        int left = max(0, findMaxPath(root->left, maxSum));
        int right = max(0, findMaxPath(root->right, maxSum));
        
        maxSum = max(maxSum, root->val + left + right);
        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
        return 0;

        if(!root->left&&!root->right)
        return root->val;

        int maxSum = INT_MIN;
        int maxi = findMaxPath(root, maxSum);

        return max(maxi,maxSum);
    }
};