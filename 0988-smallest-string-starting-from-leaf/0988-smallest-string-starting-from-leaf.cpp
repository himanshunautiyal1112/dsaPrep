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
    void find(TreeNode* root, string &s, vector<int>& arr, vector<string>& ans) {
        if(!root)
        return;

        if(!root->left && !root->right) {
            arr.push_back(root->val);
            reverse(arr.begin(), arr.end());
            for(auto n: arr) {
                char c = 'a' + n;
                s+=c;
            }
            reverse(arr.begin(), arr.end());
            ans.push_back(s);
            arr.pop_back();
            s = "";
            return;
        }

        arr.push_back(root->val);

        find(root->left, s, arr, ans);
        find(root->right, s, arr, ans);

        arr.pop_back();
    }

    bool cmp(const string& a, const string& b) {
        return a < b;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string s;
        vector<int> arr;
        vector<string> ans;
        find(root, s, arr, ans);

        sort(ans.begin(), ans.end(), [](const string& a, const string& b) {
        return a < b;
        });
        return ans[0];
    }
};