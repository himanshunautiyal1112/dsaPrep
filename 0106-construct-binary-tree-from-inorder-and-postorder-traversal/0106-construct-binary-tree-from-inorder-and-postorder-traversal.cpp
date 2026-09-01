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
    // int find(vector<int> inorder, int target, int st, int end) {
    //     for(int i=st; i<=end; i++) 
    //     if(inorder[i] == target)
    //     return i;

    //     return -1;
    // }
    TreeNode* tree(vector<int> &inorder, vector<int> &postorder, int start, int end, int index, unordered_map<int, int>& mp) {
        if(start > end)
        return NULL;
        
        TreeNode* root = new TreeNode(postorder[index]);
        
        int pos = mp[postorder[index]];
        
        // right
        root->right = tree(inorder, postorder, pos+1, end, index-1, mp);
        // left
        root->left = tree(inorder, postorder, start, pos-1, index-(end-pos)-1, mp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;

        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return tree(inorder, postorder, 0, postorder.size()-1, postorder.size()-1, mp);
    }
};