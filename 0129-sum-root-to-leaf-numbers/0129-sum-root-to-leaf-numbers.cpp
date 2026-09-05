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
    void find(TreeNode* root, string &s, int &sum) {
        if(!root)
        return;

        int n = s.size();

        if(!root->left && !root->right) {
            s+=to_string(root->val);
            sum = sum + stoi(s);
            s = s.substr(0, n);
            return;
        }
        s+=to_string(root->val);
        find(root->left, s, sum);
        find(root->right, s, sum);

        s = s.substr(0, n);

    }
    int sumNumbers(TreeNode* root) {
        string s;
        int sum = 0;
        find(root, s, sum);

        return sum;
    }
};