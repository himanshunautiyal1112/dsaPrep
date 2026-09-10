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
    //BASIC OR BRUTE FORCE T.C(O(N)) S.C[O(N)]
    // void inorder(TreeNode* root, vector<int>& arr) {
    //     if(!root)
    //     return;

    //     inorder(root->left, arr);
    //     arr.push_back(root->val);
    //     inorder(root->right, arr);
    // }
    // void consrtuct(TreeNode* root,  vector<int>& arr, int &index) {
    //     if(!root)
    //     return;

    //     consrtuct(root->left, arr, index);
    //     root->val = arr[index++];
    //     consrtuct(root->right, arr, index);
    // }

    //OPTIMAL METHOD [ USING MORRIS TRAVERSAL] TC[O(N)] S.C[O(1)];
    void recoverTree(TreeNode* root) {
        TreeNode* curr = NULL, *prev = NULL, *first = NULL, *second = NULL;

        while(root) {
            if(!root->left) {
                prev = curr;
                curr = root;

                if(prev && prev->val > curr->val) {
                    if(!first)
                    first = prev;

                    second = curr;
                }

                root = root->right;
            } else {
                TreeNode* temp = root->left;

                while(temp->right && temp->right != root)
                temp = temp->right;

                if(!temp->right) {
                    temp->right = root;
                    root = root->left;
                } else {
                    temp->right = NULL;
                    prev = curr;
                    curr = root;

                    if(prev && prev->val > curr->val) {
                        if(!first)
                        first = prev;

                        second = curr;
                    }

                    root = root->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};