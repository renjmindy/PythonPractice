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
    bool found(TreeNode *root, int k, set<int>& tgt) {
        if (!root) {
            return false;
        }
        if (tgt.count(root->val)) {
            return true;
        }
        tgt.insert(k - root->val);
        return found(root->left, k, tgt) || found(root->right, k, tgt);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> tgt;
        return found(root, k, tgt);
    }
};
