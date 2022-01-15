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
    void inorderBST(TreeNode* root, vector<int>& ans, int k) {
        if (root == NULL) return;
        inorderBST(root->left, ans, k);
        ans.push_back(root->val);
        inorderBST(root->right, ans, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderBST(root, ans, k);
        return ans[k-1];
    }
};
