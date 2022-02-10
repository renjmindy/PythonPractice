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
public:
    
    TreeNode* construct(vector<int> &nums, int l, int r) {
        
        int index = -1, maxNode = INT_MIN;
        for (int i = l; i <= r; i++) {
            if (nums[i] > maxNode) {
                maxNode = nums[i];
                index = i;
            }
        }
        
        if (maxNode == INT_MIN) {
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(maxNode);
        root->left = construct(nums, l, index - 1);
        root->right = construct(nums, index + 1, r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};
