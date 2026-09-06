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
    TreeNode* insert(TreeNode* root, int target) {
        if(!root) {
            TreeNode* temp = new TreeNode(target);
            return temp;
        }

        if(target < root->val) {
            root->left = insert(root->left, target);
        } else {
            root->right = insert(root->right, target);
        }

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return root = insert(root, val);
    }
};