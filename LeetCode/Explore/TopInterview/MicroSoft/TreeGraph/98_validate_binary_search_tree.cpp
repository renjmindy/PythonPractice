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
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
  
public:
    bool isValidBST(TreeNode* root, long Min = LONG_MIN, long Max = LONG_MAX) {
      if (!root) {
        return true;
      }
      if (root->val <= Min || root->val >= Max) {
        return false;
      }
      return isValidBST(root->left, Min, root->val) && isValidBST(root->right, root->val, Max);
    }
};
