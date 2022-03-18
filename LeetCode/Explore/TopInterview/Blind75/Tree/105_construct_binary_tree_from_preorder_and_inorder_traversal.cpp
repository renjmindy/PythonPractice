// DFS

// Complexity analysis
// Let NN be the length of the input arrays.
// Time complexity : O(N)O(N).
// Building the hashmap takes O(N)O(N) time, as there are NN nodes to add, and adding items to a hashmap has a cost of O(1)O(1), 
// so we get N \cdot O(1) = O(N)N⋅O(1)=O(N). Building the tree also takes O(N)O(N) time. The recursive helper method has a cost of O(1)O(1) 
// for each call (it has no loops), and it is called once for each of the NN nodes, giving a total of O(N)O(N).
// Taking both into consideration, the time complexity is O(N)O(N).
// Space complexity : O(N)O(N).
// Building the hashmap and storing the entire tree each requires O(N)O(N) memory. The size of the implicit system stack used by recursion calls 
// depends on the height of the tree, which is O(N)O(N) in the worst case and O(\log N)O(logN) on average. Taking both into consideration, the space 
// complexity is O(N)O(N).

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
  int preidx = 0;
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int is, int ie) {
    if (is > ie) {
      return nullptr;
    }
    // call preorder
    TreeNode *root = new TreeNode(preorder[preidx]);
    preidx++;
    // loop inorder to find root
    int inidx = 0;
    for (int i = is; i <= ie; i++) {
      if (inorder[i] == root->val) {
        inidx = i;
        break;
      }
    }
    // recursion called around root
    root->left = dfs(preorder, inorder, is, inidx - 1);
    root->right = dfs(preorder, inorder, inidx + 1, ie);
    return root;
  }
  
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int is = 0, ie = inorder.size() - 1;
    return dfs(preorder, inorder, is, ie);
  }
};
