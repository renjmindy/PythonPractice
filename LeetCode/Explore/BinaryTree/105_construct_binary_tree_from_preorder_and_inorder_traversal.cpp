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
  int preIdx;
  unordered_map<int, int> mp;
  TreeNode* rec(int l, int r, vector<int> &preorder) {
    // if there are no elements to construct the tree
    if (l > r) {
      return nullptr;
    }
    // select the preorder_index element as the root and increment it
    int t = preorder[preIdx++];
    TreeNode *head = new TreeNode(t);

    // build left and right subtree
    // excluding inorderIndexMap[rootValue] element because it's the root
    head->left = rec(l, mp[t] - 1, preorder);
    head->right = rec(mp[t] + 1, r, preorder);
    return head;
  }
  
public: 
  TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
    preIdx = 0;
    // build a hashmap to store value -> its index relations
    for (int i = 0; i < inorder.size(); i++) {
      mp.insert({inorder[i], i});
    }
    TreeNode *head = rec(0, preorder.size() - 1, preorder);
    return head;
  }
};
