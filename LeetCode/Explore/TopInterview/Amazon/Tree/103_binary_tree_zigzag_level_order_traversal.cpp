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
  int findHeight(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return 1 + max(findHeight(root->left), findHeight(root->right));
  }
  
  void preOrder(TreeNode *root, int level, vector<int> &vp) {
    if (!root) {
      return;
    }
    if (level == 0) {
      vp.push_back(root->val);
      return;
    }
    preOrder(root->left, level - 1, vp);
    preOrder(root->right, level - 1, vp);
  }
  
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int> > ans;
      for (int i = 0; i < findHeight(root); i++) {
        vector<int> vp;
        preOrder(root, i, vp);
        if (i & 1) {
          reverse(vp.begin(), vp.end());
        }
        ans.push_back(vp);
      }
      return ans;
    }
};
