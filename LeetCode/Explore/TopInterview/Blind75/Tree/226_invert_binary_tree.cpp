// Recursive

// Complexity Analysis
// Since each node in the tree is visited only once, the time complexity is O(n)O(n), where nn is the number of nodes in the tree. 
// We cannot do better than that, since at the very least we have to visit each node to invert it.
// Because of recursion, O(h)O(h) function calls will be placed on the stack in the worst case, where hh is the height of the tree. 
// Because h\in O(n)h∈O(n), the space complexity is O(n)O(n).

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
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    root->right = l;
    root->left = r;
    return root;
  }
};
