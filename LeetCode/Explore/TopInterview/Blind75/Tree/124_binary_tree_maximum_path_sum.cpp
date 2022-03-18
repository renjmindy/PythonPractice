// Recursion

// Complexity Analysis
// Time complexity: \mathcal{O}(N)O(N), where N is number of nodes, since we visit each node not more than 2 times.
// Space complexity: \mathcal{O}(H)O(H), where HH is a tree height, to keep the recursion stack. 
// In the average case of balanced tree, the tree height H = \log NH=logN, in the worst case of skewed tree, H = NH=N.

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
  int maxSum = INT_MIN;
  int maxGain(TreeNode *root) {
    if (!root) {
      return 0;
    }
    // max sum on left and right subtrees of nodes
    int leftGain = max(maxGain(root->left), 0);
    int rightGain = max(maxGain(root->right), 0);
    
    // price to start new path where node is highest
    int priceNewPath = root->val + leftGain + rightGain;
    
    // update maxSum if it's better to start new path
    maxSum = max(maxSum, priceNewPath);
    
    // for recursion:
    // return max gain if continue same path
    return root->val + max(leftGain, rightGain);
    
  }
  
public:
  int maxPathSum(TreeNode* root) {
    maxGain(root);
    return maxSum;
  }
};
