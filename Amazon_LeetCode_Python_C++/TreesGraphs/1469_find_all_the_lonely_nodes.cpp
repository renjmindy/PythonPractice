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
    
private:
    vector<int> ans;
    void preOrder(TreeNode *root, vector<int> &ans) {
        if (!root) {
            return;
        }
        if (!(root->left && root->right) && (!(root->left) || !(root->right))) {
            if (root->left) {
                ans.push_back(root->left->val);
            }
            else if (root->right) {
                ans.push_back(root->right->val);
            }
        }
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        preOrder(root, ans);
        return ans;
    }
};
