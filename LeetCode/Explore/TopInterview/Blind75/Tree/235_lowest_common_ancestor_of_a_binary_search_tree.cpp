// Recursive

// Complexity Analysis
// Time Complexity: O(N)O(N), where NN is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.
// Space Complexity: O(N)O(N). This is because the maximum amount of space utilized by the recursion stack would be NN since the height of 
// a skewed BST could be NN.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int rootVal = root->val, pVal = p->val, qVal = q->val;
    
    if (pVal > rootVal && qVal > rootVal) {
      // If both p and q are greater than parent
      return lowestCommonAncestor(root->right, p, q);
    }
    else if (pVal < rootVal && qVal < rootVal) {
      // If both p and q are lesser than parent
      return lowestCommonAncestor(root->left, p, q);
    }
    else {
      // We have found the split point, i.e. the LCA node.
      return root;
    }
  }
};
