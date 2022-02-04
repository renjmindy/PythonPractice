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
    void noRight(TreeNode* node, TreeNode* p) {
        if (!node) {
            return;
        }
        this->noRight(node->left, p);
        if (this->pre == p && !(this->suc)) {
            this->suc = node;
            return;
        }
        this->pre = node;
        this->noRight(node->right, p);
    }
    
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            TreeNode *lmost = p->right;
            while (lmost) {
                lmost = lmost->left;
            }
            this->suc = lmost;
        }
        else {
            this->noRight(root, p);
        }
        return this->suc;
    }
};
