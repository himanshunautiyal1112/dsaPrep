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
class BSTIterator {
public:
    TreeNode* r;
    vector<int>in;
    int index = 0;
    BSTIterator(TreeNode* root) {
        r = root;
        inorder(r);
    }

    void inorder(TreeNode* r1) {
        if(!r1)
        return;

        inorder(r1->left);
        in.push_back(r1->val);
        inorder(r1->right);
    }
    
    int next() {
        return in[index++];
    }
    
    bool hasNext() {
        return (index < in.size()) ? 1: 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */