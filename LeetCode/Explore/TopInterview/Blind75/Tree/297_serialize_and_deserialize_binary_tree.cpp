// Depth First Search (DFS)

// Complexity Analysis
// Time complexity : in both serialization and deserialization functions, we visit each node exactly once, thus the time complexity is O(N)O(N), 
// where NN is the number of nodes, i.e. the size of tree.
// Space complexity : in both serialization and deserialization functions, we keep the entire tree, either at the beginning or at the end, therefore, 
// the space complexity is O(N)O(N).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  
private:
  TreeNode *dfs(string &data) {
    if (data[0] == '#') {
      if (data.size() > 1) {
        data = data.substr(2);
      }
      return nullptr;
    }
    size_t size;
    TreeNode *node = new TreeNode(stoi(data, &size));
    data = data.substr(size + 1);
    node->left = dfs(data);
    node->right = dfs(data);
    return node;
  }
  
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if (!root) {
        return "#";
      }
      return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      return dfs(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
