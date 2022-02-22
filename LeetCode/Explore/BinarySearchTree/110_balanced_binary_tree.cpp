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
  int maxHeight(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
  }
  
public:
  bool isBalanced(TreeNode* root) {
    if (!root) {
      return true;
    }
    return abs(maxHeight(root->left) - maxHeight(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
  }
};
