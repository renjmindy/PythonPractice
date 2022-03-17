// Prefix Sum

// Complexity Analysis
// Time complexity: \mathcal{O}(N)O(N), where NN is a number of nodes. During preorder traversal, each node is visited once.
// Space complexity: up to \mathcal{O}(N)O(N) to keep the hashmap of prefix sums, where NN is a number of nodes.

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
  int count = 0;
  vector<int> vp;
  void preOrder(TreeNode *root, int targetSum, int &count, vector<int> &vp) {
    if (!root) {
      return;
    }
    
    // add current node to vector
    vp.push_back(root->val);
    
    // recurse left and right children
    preOrder(root->left, targetSum, count, vp);
    preOrder(root->right, targetSum, count, vp);
    
    int sum = 0;
    for (int i = vp.size() - 1; i >= 0; i--) {
      sum += vp[i];
      if (sum == targetSum) {
        count++;
      }
    }
    vp.pop_back();
  }
  
public:
  int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return 0;
    }
    preOrder(root, targetSum, count, vp);
    return count;
  }
};
