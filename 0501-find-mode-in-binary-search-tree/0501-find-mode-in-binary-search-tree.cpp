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
    void find(TreeNode* root, unordered_map<int, int>& mp) {
        if(!root)
        return;

        mp[root->val]++;
        find(root->left, mp);
        find(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int>ans;

        if(!root) return {};

        if(!root->left && !root->right){
            ans.push_back(root->val);
            return ans;
        }

        find(root, mp);

        vector<pair<int,int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second>b.second;
        });

        int maxfreq = vec[0].second;

        for(auto p: vec) {
            if(p.second == maxfreq)
            ans.push_back(p.first);
            else 
            break;
        }

        return ans;
    }
};