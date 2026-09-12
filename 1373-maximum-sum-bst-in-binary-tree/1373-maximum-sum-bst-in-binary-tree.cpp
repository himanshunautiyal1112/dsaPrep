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
        int sum;
        int minValue, maxValue;
        
        Box() {
            BST = 1;
            sum = 0;
            minValue = INT_MAX;
            maxValue = INT_MIN;
        }
};
class Solution {
public:
    Box find(TreeNode* root, int &maxSum) {
        if(!root) {
            return Box();
        }

        Box left = find(root->left, maxSum);
        Box right = find(root->right, maxSum);

        if(left.BST && right.BST && left.maxValue < root->val && right.minValue > root->val) {
            Box head = Box();

            head.sum = root->val + left.sum + right.sum;
            head.minValue = min(root->val, left.minValue);
            head.maxValue = max(root->val, right.maxValue);

            maxSum = max(maxSum, head.sum);
            return head;
        } else {
            left.BST = 0;
            return left;
        }
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        find(root, maxSum);

        return maxSum;
    }
};