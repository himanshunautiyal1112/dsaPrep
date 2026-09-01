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
    int find(vector<int> inorder, int target, int st, int end) {

        for(int i=st; i<=end; i++) {
            if(inorder[i] == target)
            return i;
        }

        return -1;
    }
    TreeNode* tree(vector<int> inorder, vector<int> preorder, int inStart, int inEnd, int index) {
        if(inStart > inEnd)
        return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int pos = find(inorder, preorder[index], inStart, inEnd);

        //left tree build
        root->left = tree(inorder, preorder, inStart, pos-1, index+1);
        // right tree build
        root->right = tree(inorder, preorder, pos+1, inEnd, index+(pos-inStart)+1);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return tree(inorder, preorder, 0, n-1, 0);
    }
};