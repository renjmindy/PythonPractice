/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Concept :

//if root is the the one of the p or q

//if one of the either p or q is present in left subtree and other one is in right subtree

//if both the value p & q is either in left or right subtree of the root.

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
      return root;
    }
    TreeNode *lcal = lowestCommonAncestor(root->left, p, q);
    TreeNode *lcar = lowestCommonAncestor(root->right, p, q);
    if (lcal && lcar) {
      return root;
    }
    else if (lcal) {
      return lcal;
    }
    else {
      return lcar;
    }
  }
};
