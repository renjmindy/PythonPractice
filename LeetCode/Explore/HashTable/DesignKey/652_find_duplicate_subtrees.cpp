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
  vector<TreeNode*> ans;
  unordered_map<string, int> mp;
  string preOrder(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode*> &ans) {
    if (!root) {
      return " ";
    }
  
    string cstr = to_string(root->val) + " " + preOrder(root->left, mp, ans) + " " + preOrder(root->right, mp, ans);
    
    if (mp[cstr] == 1) {
      ans.push_back(root);
    }
    
    mp[cstr]++;
    return cstr;
  }
  
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    preOrder(root, mp, ans);
    return ans;
  }
};
