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
    TreeNode *pre = nullptr;
    bool inOrder(TreeNode *root) {
        if (!root) {
            return true;
        }
        if (!inOrder(root->left)) {
            return false;
        }
        if (pre && root->val <= pre->val) {
            return false;
        }
        pre = root;
        return inOrder(root->right);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return false;
        }
        return inOrder(root);
    }
};
