// Depth First Traversal | Recursion

// Complexity Analysis

// Time Complexity: O(N^2)O(N2) where NN are the number of nodes in a tree. In the worst case, we could have a complete binary tree and if that is the case, 
// then there would be N/2N/2 leafs. For every leaf, we perform a potential O(N)O(N) operation of copying over the pathNodes nodes to a new list to be added 
// to the final pathsList. Hence, the complexity in the worst case could be O(N^2)O(N2).
// Space Complexity: O(N)O(N). The space complexity, like many other problems is debatable here. I personally choose not to consider the space occupied by 
// the output in the space complexity. So, all the new lists that we create for the paths are actually a part of the output and hence, don't count towards 
// the final space complexity. The only additional space that we use is the pathNodes list to keep track of nodes along a branch. We could include the space 
// occupied by the new lists (and hence the output) in the space complexity and in that case the space would be O(N^2)O(N2). There's a great answer on Stack 
// Overflow about whether to consider input and output space in the space complexity or not. I prefer not to include them.

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
  vector<int> vp;
  vector<vector<int> > ans;
  void recurseTree(TreeNode *root, int targetSum, vector<int> &vp, vector<vector<int> > &ans) {
    if (!root) {
      return;
    }
    // add current node to vector
    vp.push_back(root->val);
    
    // check if current node is a leaf and also, if it equals our remaining sum.
    // if it does, we add path to list of vectors
    if (targetSum == root->val && !root->left && !root->right) {
      ans.push_back(vp);
    }
    else {
      // otherwise, we will recurse left and right children
      recurseTree(root->left, targetSum - root->val, vp, ans);
      recurseTree(root->right, targetSum - root->val, vp, ans);
    }
    // we need to pop node once we are done with processing all subtrees
    vp.pop_back();
  }
  
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    recurseTree(root, targetSum, vp, ans);
    return ans;
  }
};
