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
    int findMax(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = findMax(root->left);
        int r = findMax(root->right);
        return 1 + max(l, r);
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (findMax(root->left) == findMax(root->right)) {
            return root;
        }
        else {
            return findMax(root->left) > findMax(root->right) ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
        }
    }
};
