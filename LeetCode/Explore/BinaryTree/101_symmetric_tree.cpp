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
  bool isSymmTree(TreeNode *l, TreeNode *r) {
    if (l == r) {
      return true;
    }
    if (!l || !r) {
      return false;
    }
    return (l->val == r->val) && (isSymmTree(l->left, r->right)) && (isSymmTree(l->right, r->left));
  }
  
public:
  bool isSymmetric(TreeNode* root) {
    return isSymmTree(root->left, root->right);
  }
};
