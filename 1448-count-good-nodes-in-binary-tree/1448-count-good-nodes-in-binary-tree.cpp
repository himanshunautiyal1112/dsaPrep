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
    void findNodes(TreeNode* root, int &count, int maxele) {
        if(!root)
        return;

        if(root->val >= maxele){
            count++;
            maxele = max(maxele, root->val);
        }

        findNodes(root->left, count, maxele);
        findNodes(root->right, count, maxele);

    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        findNodes(root, count, root->val);

        return count;
    }
};