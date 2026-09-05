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
    void find(TreeNode* root, vector<int>& arr, vector<string>& ans) {
        if(!root)
        return;

        if(!root->left && !root->right) {
            string s = "";
            arr.push_back(root->val);
            for(int i=arr.size()-1; i>=0; i--) {
                char c = 'a' + arr[i];
                s+=c;
            }
            ans.push_back(s);
            arr.pop_back();
            s = "";
            return;
        }

        arr.push_back(root->val);

        find(root->left, arr, ans);
        find(root->right, arr, ans);

        arr.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<int> arr;
        vector<string> ans;
        find(root, arr, ans);

        sort(ans.begin(), ans.end());
        return ans[0];
    }
};