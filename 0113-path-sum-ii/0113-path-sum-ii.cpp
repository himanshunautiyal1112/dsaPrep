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
    void findPath(TreeNode* root, int target, vector<vector<int>>& ans, vector<int> &arr) {
        if(!root)
        return;

        if(!root->left && !root->right) {
            if(target - root->val == 0) {
                arr.push_back(root->val);
                ans.push_back(arr);
                arr.pop_back();
                return;
            }
            return;
        }

        arr.push_back(root->val);
        findPath(root->left, target-root->val, ans, arr);
        findPath(root->right, target-root->val, ans, arr);
        arr.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;

        findPath(root, targetSum, ans, arr);

        return ans;
    }
};