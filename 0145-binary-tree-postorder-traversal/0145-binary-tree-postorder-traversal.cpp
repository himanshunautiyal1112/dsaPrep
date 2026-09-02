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
    void post(TreeNode* root, vector<int> &ans) {
        if(!root)
        return;

        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //post(root, ans);

        while(root) {
            if(!root->right) {
                ans.push_back(root->val);
                root = root->left;
            } else {
                TreeNode* temp = root->right;

                while(temp->left && temp->left != root)
                temp = temp->left;

                if(!temp->left) {
                    ans.push_back(root->val);
                    temp->left = root;
                    root = root->right;
                } else {
                    temp->left = NULL;
                    root = root->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};