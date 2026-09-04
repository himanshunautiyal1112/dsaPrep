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
    int heightL(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }
        return height;
    }
    int heightR(TreeNode* root) {
        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }
        return height;
    }
    int count(TreeNode* root) {
       if(!root)
       return 0;

       int lh = heightL(root);
       int rh = heightR(root);

       if(lh==rh) {
        return (1<<lh)-1;
       }

       return 1+count(root->left) + count(root->right);
    }
    int countNodes(TreeNode* root) {
        return count(root);
    }
};