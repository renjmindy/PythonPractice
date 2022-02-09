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
    vector<int> nums;
    
    void inOrder(TreeNode *root, vector<int> &nums) {
        if (!root) {
            return;
        }
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    
public:
    int closestValue(TreeNode* root, double target) {
        inOrder(root, nums);
        int minLeaf = 0; 
        double minVal = DBL_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (minVal > abs(nums[i] - target)) {
                minVal = abs(nums[i] - target);
                minLeaf = nums[i];
            }
        }
        return minLeaf;
    }
};
