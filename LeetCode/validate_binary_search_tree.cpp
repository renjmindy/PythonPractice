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
    
    bool isBST(TreeNode* root, TreeNode* l, TreeNode* h) {
        if (root == NULL) return true;
        if ((l != NULL && root->val <= l->val) || (h != NULL && root->val >= h->val)) {
            return false;
        }
        return isBST(root->left, l, root) && isBST(root->right, root, h);
}

    
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};
