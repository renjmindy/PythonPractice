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
    map<int, map<int, vector<int> > > mp;
    void preOrder(TreeNode *root, int row, int col, map<int, map<int, vector<int> > > &mp) {
        if (!root) {
            return;
        }
        mp[col][row].push_back(root->val);
        preOrder(root->left, row + 1, col - 1, mp);
        preOrder(root->right, row + 1, col + 1, mp);
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) {
            return ans;
        }
        preOrder(root, 0, 0, mp);
        for(auto &m : mp) {
            map<int, vector<int>> n = m.second;
            vector<int> tmp;
            for(auto &x1 : n) {
                for(auto &x2 : x1.second) {
                    tmp.push_back(x2);
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
