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
    int findMin(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = findMin(root->left);
        int r = findMin(root->right);
        return (l == 0 || r == 0) ? (l + r) + 1 : min(l, r) + 1;
        //return max(l, r) + 1; // for maximum
    }
    
public:
    int minDepth(TreeNode* root) {
        /*if (!root) {
            return 0;
        }
        if (!(root->left) || !(root->right)) {
            return 1;
        }
        int minVal = INT_MAX;
        if (root->left) {
            minVal = min(minVal, minDepth(root->left));
        }
        if (root->right) {
            minVal = min(minVal, minDepth(root->right));
        }
        return minVal + 1;*/
        return findMin(root);
    }
};
