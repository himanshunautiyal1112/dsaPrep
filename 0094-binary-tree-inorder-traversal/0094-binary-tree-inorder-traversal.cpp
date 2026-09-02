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
    void inor(TreeNode* root, vector<int> &ans) {
        if(!root)
        return;

        inor(root->left, ans);
        ans.push_back(root->val);
        inor(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inor(root, ans);

         while(root) {
            if(!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                
                while(temp->right && temp->right != root)
                temp = temp->right;
                
                if(!temp->right) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};