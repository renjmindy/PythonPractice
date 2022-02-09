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
    int ans = 0;
    int postOrder(TreeNode *root, int &ans) {
        if (!root) {
            return 0;
        }
        int l = postOrder(root->left, ans);
        int r = postOrder(root->right, ans);
        ans += abs(l - r);
        return root->val + l + r;
    }
    
public:
    int findTilt(TreeNode* root) {
        if (!root) {
            return 0;
        }
        postOrder(root, ans);
        return ans;
    }
};
