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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
  }
  
public:
    bool isSymmetric(TreeNode* root) {
      if (!root) {
        return true;
      }
      return isSameTree(root->left, root->right);
    }
};
