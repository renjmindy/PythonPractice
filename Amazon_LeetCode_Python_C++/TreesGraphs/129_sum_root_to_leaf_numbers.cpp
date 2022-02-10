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
    void preOrder(TreeNode *root, int cur) {
        if (!root) {
            return;
        }
        /*cur = cur * 10 + root->val;
        if (!root->left && !root->right) {
            ans += cur;
        }
        preOrder(root->left, cur);
        preOrder(root->right, cur);*/
        
        if (root->left) {
            preOrder(root->left, cur * 10 + root->val);
        }
        
        if (root->right) {
            preOrder(root->right, cur * 10 + root->val);
        }
        
        if (!root->left && !root->right) {
            ans += cur * 10 + root->val;
        }
        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        preOrder(root, 0);
        return ans;
    }
};
