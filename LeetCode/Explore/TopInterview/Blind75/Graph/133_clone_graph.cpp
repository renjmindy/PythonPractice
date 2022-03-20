// DFS

// Complexity Analysis
// Time Complexity: O(N + M)O(N+M), where NN is a number of nodes (vertices) and MM is a number of edges.
// Space Complexity: O(N)O(N). This space is occupied by the visited hash map and in addition to that, space 
// would also be occupied by the recursion stack since we are adopting a recursive approach here. The space 
// occupied by the recursion stack would be equal to O(H)O(H) where HH is the height of the graph. Overall, the space complexity would be O(N)O(N).

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  
private:  
  unordered_map<Node*, Node*> mp;
  
public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return node;
    }
    
    // If the node was already visited before.
    // Return the clone from the visited dictionary.
    // (mp.find(node) != mp.end()) {}
    if (mp.count(node)) {
      return mp[node];
    }
    else {
      // Create a clone for the given node.
      // Note that we don't have cloned neighbors as of now, hence [].
      mp[node] = new Node(node->val, {}); // make a copy
      // The key is original node and value being the clone node.
      // Iterate through the neighbors to generate their clones
      // and prepare a list of cloned neighbors to be added to the cloned node.
      for (auto &i : node->neighbors) { // traverse adjacent 
        mp[node]->neighbors.push_back(cloneGraph(i)); // add copy
      }
    }
    return mp[node]; // return mp[node] as till now whole graph cloned
  }
};
