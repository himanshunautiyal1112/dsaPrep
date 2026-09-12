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
 class Box {
    public:
        bool BST;
        int size;
        int minValue, maxValue;
        
        Box(int data) {
            BST = 1;
            size = data;
            minValue = data;
            maxValue = data;
        }
};
class Solution {
public:
    Box* find(TreeNode* root, int &maxSum) {
        if(!root->left && !root->right) {
            maxSum = max(maxSum, root->val);
            return new Box(root->val);
        }
        else if(!root->left && root->right) {
            Box* head = find(root->right, maxSum);
            
            if(head->BST && head->minValue > root->val) {
                head->size+=root->val;
                head->minValue = root->val;
                maxSum = max(maxSum, head->size);
                return head;
            } else {
                head->BST = 0;
                return head;
            }
        }
        else if(root->left && !root->right) {
            Box* head = find(root->left, maxSum);
            
            if(head->BST && head->maxValue < root->val) {
                head->size+=root->val;
                head->maxValue = root->val;
                maxSum = max(maxSum, head->size);
                return head;
            } else {
                head->BST = 0;
                return head;
            }
        } else {
            Box* left = find(root->left, maxSum);
            Box* right = find(root->right, maxSum);
            
            if(left->BST && right->BST && left->maxValue < root->val && right->minValue > root->val) {
                Box* head = new Box(root->val);
                
                head->size += left->size + right->size;
                head->minValue = left->minValue;
                head->maxValue = right->maxValue;
                
                maxSum = max(maxSum, head->size);
                
                return head;
            } else {
                left->BST = 0;
                return left;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        find(root, maxSum);

        return maxSum;
    }
};