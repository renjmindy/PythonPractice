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
  bool isuni = true;
  int ans = 0;
  void isUniTree(TreeNode *root, bool &isuni, int &ans) {
    if (!root->left && !root->right) {
      ans++;
      isuni = true;
    }
    else {
      bool isluni = true, isruni = true;
      if (root->left) {
        isUniTree(root->left, isuni, ans);
        isluni = isuni && (root->val == root->left->val);
      }
      if (root->right) {
        isUniTree(root->right, isuni, ans);
        isruni = isuni && (root->val == root->right->val);
      }
      if (isluni && isruni) {
        ans++;
      }
      else {
        isuni = false;
      }
    }
  }
  
public:
  int countUnivalSubtrees(TreeNode* root) {
    if (!root) {
      return 0;
    }
    isUniTree(root, isuni, ans);
    return ans;
  }
};
