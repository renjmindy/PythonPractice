// Recursion

// Complexity analysis
// Time complexity : we visit each node exactly once, thus the time complexity is \mathcal{O}(N)O(N), where NN is the number of nodes.
// Space complexity : in the worst case, the tree is completely unbalanced, e.g. each node has only left child node, the recursion call 
// would occur NN times (the height of the tree), therefore the storage to keep the call stack would be \mathcal{O}(N)O(N). 
// But in the best case (the tree is completely balanced), the height of the tree would be \log(N)log(N). 
// Therefore, the space complexity in this case would be \mathcal{O}(\log(N))O(log(N)).

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
  int maxDepth(TreeNode* root) {
    if (!root) { // base case
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
