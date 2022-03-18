// Recursion

// Complexity Analysis
// Time complexity : \mathcal{O}(N)O(N) since each node is processed exactly once.
// Space complexity : \mathcal{O}(N)O(N) to keep the output structure which contains N node values.

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
  vector<vector<int> > vp;
  void preOrder(TreeNode *root, int level, vector<vector<int> > &vp) {
    if (!root) { // base case
      return;
    }
    if (level == vp.size()) {
      vp.push_back({root->val});
    }
    else {
      vp[level].push_back(root->val);
    }
    if (root->left) {
      preOrder(root->left, level + 1, vp);
    }
    if (root->right) {
      preOrder(root->right, level + 1, vp);
    }
  }
  
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
      return vp;
    }
    preOrder(root, 0, vp);
    return vp;
  }
};
