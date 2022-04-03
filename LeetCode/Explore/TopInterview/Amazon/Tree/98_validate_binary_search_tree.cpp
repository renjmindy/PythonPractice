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
    bool isValidBST(TreeNode* root, long MIN = LONG_MIN, long MAX = LONG_MAX) {
      if (!root) {
        return true;
      }
      if (root->val >= MAX || root->val <= MIN) {
        return false;
      }
      return isValidBST(root->left, MIN, root->val) && isValidBST(root->right, root->val, MAX);
    }
};
