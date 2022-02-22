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
  TreeNode* preOrder(int l, int r, vector<int> &nums) {
    if (l <= r) {
      int pivot = l + (r - l) / 2;
      TreeNode *root = new TreeNode(nums[pivot]);
      root->left = preOrder(l, pivot - 1, nums);
      root->right = preOrder(pivot + 1, r, nums);
      return root;
    }
    return nullptr;
  }
  
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return preOrder(0, nums.size() - 1, nums);
  }
};
