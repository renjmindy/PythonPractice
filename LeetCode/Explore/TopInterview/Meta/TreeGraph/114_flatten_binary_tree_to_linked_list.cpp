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
  TreeNode* dfs(TreeNode *root) {
    if (!root) {
      return nullptr;
    }
    if (!root->left && !root->right) {
      return root;
    }
    TreeNode *l = dfs(root->left);
    TreeNode *r = dfs(root->right);
    if (l) {
      l->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
    return r ? r : l;
  }
  
public:
    void flatten(TreeNode* root) {
      dfs(root);
    }
};
