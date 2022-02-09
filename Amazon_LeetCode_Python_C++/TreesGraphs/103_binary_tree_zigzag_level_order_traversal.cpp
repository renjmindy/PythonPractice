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
    vector<int> ans;
    
    int findMax(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = findMax(root->left);
        int r = findMax(root->right);
        return 1 + max(l, r);
    }
    
    void preOrder(TreeNode *root, int level, vector<int> &ans) {
        if (!root) {
            return;
        }
        if (level == 0) {
            ans.push_back(root->val);
            return;
        }
        preOrder(root->left, level - 1, ans);
        preOrder(root->right, level - 1, ans);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        for (int i = 0; i < findMax(root); i++) {
            vector<int> ans;
            preOrder(root, i, ans);
            if (i % 2) {
                reverse(ans.begin(), ans.end());
            } 
            res.push_back(ans);
        }
        return res;
    }
};
