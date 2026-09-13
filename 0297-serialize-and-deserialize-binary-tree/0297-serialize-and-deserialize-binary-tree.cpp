/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(!temp) {
                s+="#,";
                continue;
            }
            s+=to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            getline(ss, s, ',');
            if(s!="#") {
                temp->left = new TreeNode(stoi(s));
                q.push(temp->left);
            }

            getline(ss, s, ',');
            if(s!="#") {
                temp->right = new TreeNode(stoi(s));
                q.push(temp->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));