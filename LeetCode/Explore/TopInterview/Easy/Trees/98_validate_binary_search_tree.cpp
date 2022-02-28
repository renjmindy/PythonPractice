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
  bool isBST(TreeNode *root, TreeNode *l, TreeNode *r) {
    if (!root) {
      return true;
    }
    if ((l && root->val <= l->val) || (r && root->val >= r->val)) {
      return false;
    }
    return isBST(root->left, l, root) && isBST(root->right, root, r);
  }
  
public:
  bool isValidBST(TreeNode* root) {
    return isBST(root, nullptr, nullptr);
  }
};
