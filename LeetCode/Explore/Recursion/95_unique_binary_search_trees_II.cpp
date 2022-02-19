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
  vector<TreeNode*> postOrder(int l, int r) {
    if (l > r) {
      return {NULL};
    }
    if (l == r) {
      return {new TreeNode(l)};
    }
    
    vector<TreeNode*> ans;
    for (int node = l; node <= r; node++) {
      vector<TreeNode*> left = postOrder(l, node - 1);
      vector<TreeNode*> right = postOrder(node + 1, r);
      for (auto node_l : left) {
        for (auto node_r : right){            
          TreeNode *rootNode = new TreeNode(node);
          rootNode->left = node_l;
          rootNode->right = node_r;
          ans.push_back(rootNode);
        }
      }
    }    
    return ans;
  }
  
public:
  vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans = postOrder(1, n);
    return ans;
  }
};
