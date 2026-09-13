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
    // void checkBST(TreeNode* root, vector<int> &ans) {
    //     if(!root)
    //     return;

    //     checkBST(root->left, ans);
    //     ans.push_back(root->val);
    //     checkBST(root->right, ans);
    // }
    bool checkBST(TreeNode* root, long long &prev) {
        if(!root)
        return 1;

        if(!checkBST(root->left, prev))
        return 0;

        if(root->val <= prev)
        return 0;

        prev = root->val;

        return checkBST(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
       long long prev = LLONG_MIN;
        //return checkBST(root, prev);
        bool valid = true;

        while(root) {
            if(!root->left) {
                if(root->val <= prev)
                valid = false;

                prev = root->val;
                root = root->right;
            } else {
                TreeNode* temp = root->left;
                while(temp->right && temp->right!= root)
                temp = temp->right;

                if(!temp->right) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;

                    if(root->val <= prev)
                    valid = false;

                    prev = root->val;
                    root = root->right;
                }
            }
        }
        return valid == false? 0: 1;
    }
};