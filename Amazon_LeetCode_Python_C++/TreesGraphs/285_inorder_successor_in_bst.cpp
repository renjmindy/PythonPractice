/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    TreeNode *pre, *suc;
    void inOrder(TreeNode *node, TreeNode *p) {
        if (!node) {
            return;
        }
        inOrder(node->left, p);
        
        if (pre == p && !suc) {
            suc = node;
            return;
        }
        pre = node;
        inOrder(node->right, p);
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            TreeNode *lmost = p->right;
            while (lmost->left) {
                lmost = lmost->left;
            }
            suc = lmost;
        }
        else {
            inOrder(root, p);
        }
        return suc;
    }
};
