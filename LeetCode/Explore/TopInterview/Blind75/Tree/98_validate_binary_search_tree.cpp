// Recursive Traversal with Valid Range

// Complexity Analysis
// Time complexity : \mathcal{O}(N)O(N) since we visit each node exactly once.
// Space complexity : \mathcal{O}(N)O(N) since we keep up to the entire tree.

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
public:
  bool isValidBST(TreeNode* root, long Min = LONG_MIN, long Max = LONG_MAX) {
    if (!root) { // base case
      return true;
    }
    if (root->val <= Min || root->val >= Max) {
      return false;
    }
    return isValidBST(root->left, Min, root->val) && isValidBST(root->right, root->val, Max);
  }
};
