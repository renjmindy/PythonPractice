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
  vector<int> ans;
  void inOrder(TreeNode *root, vector<int> &ans) {
    if (!root) {
      return;
    }
    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
  }
  
public:
    vector<int> inorderTraversal(TreeNode* root) {
      inOrder(root, ans);
      return ans;
    }
};
