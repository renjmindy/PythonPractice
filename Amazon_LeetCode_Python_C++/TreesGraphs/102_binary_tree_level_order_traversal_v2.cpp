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
    vector<vector<int> > ans;
    void preOrder(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (!root) {
            return;
        }
        if (level == ans.size()) {
            ans.push_back({root->val});
        }
        else {
            ans[level].push_back(root->val);
        }
        preOrder(root->left, level + 1, ans);
        preOrder(root->right, level + 1, ans);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        preOrder(root, 0, ans);
        return ans;
    }
};
