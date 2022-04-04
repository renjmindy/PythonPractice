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
  int calcSum(TreeNode *root, int &ans) {
    if (!root) {
      return 0;
    }
    // This is just to calculate the maximum path from left and right of the root.
    int lmax = max(calcSum(root->left, ans), 0);
    int rmax = max(calcSum(root->right, ans), 0);
    // Comparison with zero is just for making sure the value isn't negative, because if it is, then simply returning zero would be sufficient as negative values won't yield any maximum result ever.
    // This part here will make changes in the ans that is passed by reference.
    ans = max(ans, root->val + lmax + rmax);
    // This part is used to return the value from a particular node, not to be confused with the part mentioned just above this. This part is the one which has a functionality similar to finding height except here we're using root->val instead of 1 as the problem demands that. It could take several other forms as well depending on the problem statements.
    return root->val + max(lmax, rmax);
  }
  
public:
    int maxPathSum(TreeNode* root) {
      int ans = INT_MIN;
      calcSum(root, ans);
      return ans;
    }
};
