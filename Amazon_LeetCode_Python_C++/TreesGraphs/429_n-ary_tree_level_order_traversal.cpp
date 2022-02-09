/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    
private:
    int maxH = 0, cur = 0; 
    vector<vector<int> > ans;
    
    int findMax(Node *root, int cur) {
        if (!root) {
            cur = 0;
        }
        /*int l = findMax(root->left);
        int r = findMax(root->right);
        return 1 + max(l, r);*/
        
        for (int i = 0; i < root->children.size(); i++) {
            findMax(root->children[i], cur + 1);
        }
        
        maxH = max(maxH, cur);
        return maxH;
        
    }
    
    void preOrder(Node *root, int level, vector<vector<int> > &ans) {
        if (!root) {
            return;
        }
        
        ans[level].push_back(root->val);
        
        for (int i = 0; i < root->children.size(); i++) {
            preOrder(root->children[i], level + 1, ans);
        }
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return ans;
        }
        
        vector<vector<int> > res(findMax(root, 1));
        preOrder(root, 0, res);
        return res;
    }
};
