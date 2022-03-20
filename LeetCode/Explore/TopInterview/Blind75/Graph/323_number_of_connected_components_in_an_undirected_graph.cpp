// Depth-First Search (DFS)

// Complexity Analysis
// Here EE = Number of edges, VV = Number of vertices.
// Time complexity: {O}(E + V)O(E+V).
// Building the adjacency list will take {O}(E)O(E) operations, as we iterate over the list of edges once, and insert each edge into two lists.
// During the DFS traversal, each vertex will only be visited once. This is because we mark each vertex as visited as soon as we see it, and 
// then we only visit vertices that are not marked as visited. In addition, when we iterate over the edge list of each vertex, we look at each 
// edge once. This has a total cost of {O}(E + V)O(E+V).
// Space complexity: {O}(E + V)O(E+V).
// Building the adjacency list will take {O}(E)O(E) space. To keep track of visited vertices, an array of size {O}(V)O(V) is required. 
// Also, the run-time stack for DFS will use {O}(V)O(V) space.

class Solution {
  
private:
  void dfs(vector<int> table[], vector<int> &vp, int src) {
    vp[src] = 1;
  
    for (int i = 0; i < table[src].size(); i++) {
      if (vp[table[src][i]] == 0) {
        dfs(table, vp, table[src][i]);
      }
    }
  }
  
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    if (n == 0) {
      return 0;
    }
    int components = 0;
    vector<int> vp(n, 0); // track visited vertices
    vector<int> table[n]; // contains all adjacent vertices of vertex v
    
    for (int i = 0; i < edges.size(); i++) {
      table[edges[i][0]].push_back(edges[i][1]);
      table[edges[i][1]].push_back(edges[i][0]);
    }
    // iterate over each vertex (src) in edges (i)
    // if not visited yet, start a DFS from it
    // add every visited vertex into vp while looping
    // over DFS
    for (int i = 0; i < n; i++) {
      if (vp[i] == 0) {
        components++;
        dfs(table, vp, i);
      }
    }
    return components;
  }
};
