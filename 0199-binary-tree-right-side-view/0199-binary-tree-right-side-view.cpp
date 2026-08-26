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
class Solution
{
    public:
    void Rv(TreeNode * root , int level , vector<int> &ans) {
        if(!root)
        return;
        
        if(level == ans.size())
        ans.push_back(root->val);
        Rv(root->right , level+1 , ans);
        Rv(root->left , level+1 , ans);
    }
    
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightSideView(TreeNode *root)
    {
        // if(!root)
        // return {};
        
        // vector<int>ans;
        // Rv(root,0,ans);
        // return ans;

        vector<int>ans;
        
        queue<TreeNode*> q;
        
        if(!root)
        return ans;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            
            for(int i=0; i<n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if(i==n-1)
                ans.push_back(temp->val);
                
                if(temp->left)
                q.push(temp->left);
                
                if(temp->right)
                q.push(temp->right);
            }
        }
        
        return ans;
    }
};