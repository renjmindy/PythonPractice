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
  bool ans = false;
  void isZeroTree(TreeNode *root, int targetSum, bool &ans) {
    if (!root) {
      return;
    }
    if (!(targetSum - root->val) && !root->left && !root->right) {
      ans = true;
    }
    if (root->left) {
      isZeroTree(root->left, targetSum - root->val, ans);
    }
    if (root->right) {
      isZeroTree(root->right, targetSum - root->val, ans);
    }
  }
  
public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }
    isZeroTree(root, targetSum, ans);
    return ans;
  }
};
