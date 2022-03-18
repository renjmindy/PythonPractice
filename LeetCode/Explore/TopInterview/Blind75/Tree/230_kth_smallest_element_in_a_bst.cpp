// Recursive Inorder Traversal

// Complexity Analysis
// Time complexity : O(N)O(N) to build a traversal.
// Space complexity : O(N)O(N) to keep an inorder traversal.

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
  vector<int> vp;
  void inOrder(TreeNode *root) {
     if (!root) {
      return;
    }
    inOrder(root->left);
    vp.push_back(root->val);
    inOrder(root->right);
  }
  
public:
  int kthSmallest(TreeNode* root, int k) {
    inOrder(root);
    return vp[k - 1];
  }
};
