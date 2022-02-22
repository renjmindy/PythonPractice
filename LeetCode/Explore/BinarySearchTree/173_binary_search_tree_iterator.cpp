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
class BSTIterator {
  
private:
  vector<int> ans;
  int i;
  void inOrder(TreeNode *root, vector<int> &ans) {
    if (!root) {
      return;
    }
    inOrder(root->left, ans);
    ans.push_back(root->val);
    inOrder(root->right, ans);
  }
  
public:
  BSTIterator(TreeNode* root) {
    inOrder(root, ans);
    i = -1;
  }
  
  int next() {
    i++;
    return ans[i];
  }
  
  bool hasNext() {
    return (i + 1 < ans.size());
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
