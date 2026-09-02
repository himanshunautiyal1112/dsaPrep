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
    int dfs(TreeNode* root, int &length) {
        if(!root)
        return 0;

        int l = dfs(root->left, length);
        int r = dfs(root->right, length);

        length = max(length, l+r);

        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;
        dfs(root, length);

        return length;
    }
};