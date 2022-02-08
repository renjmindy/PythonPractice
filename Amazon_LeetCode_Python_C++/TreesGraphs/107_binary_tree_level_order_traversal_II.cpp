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
    vector<int> tmp;
    
    int findMax(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = findMax(root->left);
        int r = findMax(root->right);
        return 1 + max(l, r);
    }
    
    void preOrder(TreeNode *root, int level, vector<int> &tmp) {
        if (!root) {
            return;
        }
        if (level == 0) {
            tmp.push_back(root->val);
            return;
        }
        preOrder(root->left, level - 1, tmp);
        preOrder(root->right, level - 1, tmp);
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) {
            return ans;
        }
        for (int i = findMax(root) - 1; i >= 0; i--) {
            vector<int> tmp;
            preOrder(root, i, tmp);
            ans.push_back(tmp);
        }
        return ans;
    }
};
