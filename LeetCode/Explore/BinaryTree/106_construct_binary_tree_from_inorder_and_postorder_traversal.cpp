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
  int postIdx = 0;
  vector<int> postorder;
  unordered_map<int, int> mp;
  TreeNode* rec(int l, int r, vector<int> &postorder) {
    if (l > r) {
      return nullptr;
    }
    
    int t = postorder[postIdx];
    TreeNode* head = new TreeNode(t);    
    postIdx--;
    head->right = rec(mp[t] + 1, r, postorder);
    head->left = rec(l, mp[t] - 1, postorder);
        
    return head;
  }
  
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      for(int i = 0; i < inorder.size(); i++) {
        mp.insert({inorder[i], i});
      }
      postIdx = inorder.size() - 1;
      TreeNode* head = rec(0, inorder.size() - 1, postorder);
      return head;  
    }
};
