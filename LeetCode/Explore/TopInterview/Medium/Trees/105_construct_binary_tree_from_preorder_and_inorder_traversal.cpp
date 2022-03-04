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
  int preorderIdx;
  unordered_map<int, int> inorderMp;
  TreeNode *arrayToTree(vector<int> &preorder, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    int rootVal = preorder[preorderIdx];
    preorderIdx++;
    
    TreeNode *root = new TreeNode(rootVal);
    root->left = arrayToTree(preorder, l, inorderMp[rootVal] - 1);
    root->right = arrayToTree(preorder, inorderMp[rootVal] + 1, r);
    return root;
  }
  
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    preorderIdx = 0;
    for (int i = 0; i < inorder.size(); i++) {
      inorderMp[inorder[i]] = i;
    }
    return arrayToTree(preorder, 0, preorder.size() - 1);
  }
};
