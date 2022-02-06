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
    long long ans;
    vector<long long> vpl, vpr;
    void preOrder(TreeNode *root, int level, long long loc) {
        if (!root) {
            return;
        }
        if (vpl.size() == level) {
            vpr.push_back(loc);
            vpl.push_back(loc);
        }
        vpr[level] = loc;
        ans = max(ans, vpr[level] - vpl[level] + 1);
        preOrder(root->left, level + 1, loc * 2 - vpl[level]);
        preOrder(root->right, level + 1, loc * 2 - vpl[level] + 1);
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        preOrder(root, 0, 1);
        return ans;
    }
};
