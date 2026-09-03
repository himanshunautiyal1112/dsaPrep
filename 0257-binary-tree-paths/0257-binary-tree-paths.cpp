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
    void totalPath(TreeNode* root, vector<string> &ans, string &s) {
        if(!root)
        return;

        int n = s.size();

        if(!root->left && !root->right) {
            s+=to_string(root->val);
            ans.push_back(s);
            s = s.substr(0, n);
            return;
        }

        s+=to_string(root->val) + "->";
        totalPath(root->left, ans, s);
        totalPath(root->right, ans, s);

        s = s.substr(0, n);

        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        totalPath(root, ans, s);

        return ans;
    }
};