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
    void find(TreeNode* root, int low, int high, int &sum) {
        if(!root)
        return;

        if(root->val > low && root->val > high) {
            find(root->left, low, high, sum);
        } 
        else if(root->val < low && root->val < high) {
            find(root->right, low, high, sum);
        } else {
            find(root->left, low, high, sum);
            sum += root->val;
            find(root->right, low, high, sum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        find(root, low, high, sum);

        return sum;
    }
};