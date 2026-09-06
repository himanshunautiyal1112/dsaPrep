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
    TreeNode* nodeDelete(TreeNode* root, int key) {
        if(!root)
        return NULL;

        if(key < root->val) {
            root->left = nodeDelete(root->left, key);
            return root;
        } else if(key > root->val) {
            root->right = nodeDelete(root->right, key);
            return root;
        } else {
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            } else if(!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else if(!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                TreeNode* child = root->left;
                TreeNode* perent = root;

                while(child->right) {
                    perent = child;
                    child = child->right;
                }

                if(perent != root) {
                    perent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                } else {
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = nodeDelete(root, key);
        return root;
    }
};