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
  TreeNode* findSubTree(TreeNode *l, TreeNode *r) {
    if (!r) {
      return l;
    }
    else {
      r->left = findSubTree(l, r->left);
    }
    return r;
  }
  
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root) {
      if (root->val == key) {
        root = findSubTree(root->left, root->right);
      }
      else if (root->val > key) {
        root->left = deleteNode(root->left, key);
      }
      else {
        root->right = deleteNode(root->right, key);
      }
    }
    return root;
  }
};
