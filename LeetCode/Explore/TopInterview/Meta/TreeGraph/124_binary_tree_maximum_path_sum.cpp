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
  int calSum(TreeNode* root, int &ans) {
    if (!root) {
      return 0;
    }
    int lmax = max(calSum(root->left, ans), 0);
    int rmax = max(calSum(root->right, ans), 0);
    ans = max(ans, root->val + lmax + rmax);
    return root->val + max(lmax, rmax);
  }
  
public:
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN;
      calSum(root, ans);
      return ans;
    }
};
