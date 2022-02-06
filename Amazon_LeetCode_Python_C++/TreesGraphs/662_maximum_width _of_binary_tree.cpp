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
    //long long ans;
    //vector<long long> vpl, vpr;
    unsigned long long result = 1;
    vector<unsigned long long> vp;
    void preOrder(TreeNode *root, int level, unsigned long long loc, vector<unsigned long long> &vp) {
        if (!root) {
            return;
        }
        /*if (vpl.size() == level) {
            vpr.push_back(loc);
            vpl.push_back(loc);
        }
        vpr[level] = loc;*/
        if (vp[level] == -1) {
            vp[level] = loc;
        }
        /*ans = max(ans, vpr[level] - vpl[level] + 1);
        preOrder(root->left, level + 1, loc * 2 - vpl[level]);
        preOrder(root->right, level + 1, loc * 2 - vpl[level] + 1);*/
        result = max(result, loc - vp[level] + 1);
        preOrder(root->left, level + 1, 2 * loc, vp);
        preOrder(root->right, level + 1, 2 * loc + 1, vp);
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        vector<unsigned long long> vp(5000, -1);
        preOrder(root, 0, 1, vp);
        return result;
    }
};
