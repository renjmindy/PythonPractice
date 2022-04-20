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
  int calSum(TreeNode *root, int &ans) {
    if (!root) {
      return 0;
    }
    int lmax = calSum(root->left, ans);
    int rmax = calSum(root->right, ans);
    
    ans = max(ans, lmax + rmax);
    return 1 + max(lmax, rmax);
  }
  
public:
    int diameterOfBinaryTree(TreeNode* root) {
      int ans = 0;
      calSum(root, ans);
      return ans;
    }
};
