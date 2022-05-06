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
  int ans;
  int maxPath(TreeNode* root, int &ans) {
    if (!root) {
      return 0;
    }
    int lmax = maxPath(root->left, ans);
    int rmax = maxPath(root->right, ans);
    ans = max(ans, lmax + rmax);
    return 1 + max(lmax, rmax);
  }
  
public:
    int diameterOfBinaryTree(TreeNode* root) {
      ans = 0;
      maxPath(root, ans);
      return ans;
    }
};
