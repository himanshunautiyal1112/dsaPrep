/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        return NULL;

        if(p->val < root->val && q->val < root->val)
        return LCA(root->left, p, q);
        else if(p->val > root->val && q->val > root->val) 
        return LCA(root->right, p ,q);
        else
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};