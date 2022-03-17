// Recursion

// Complexity Analysis
// Time complexity : \mathcal{O}(N)O(N), where N is a number of nodes in the tree, since one visits each node exactly once.
// Space complexity : \mathcal{O}(\log(N))O(log(N)) in the best case of completely balanced tree and \mathcal{O}(N)O(N) in 
// the worst case of completely unbalanced tree, to keep a recursion stack.

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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
