class Solution {
  
private:
  bool dfs(int cur, vector<int> &visited, vector<vector<int> > &adj) {
    if (visited[cur] == 2) { // already visited, loop detected !
      return false;
    }
    else if (visited[cur] == 1) { // visiting, never mind
      return true;
    }
    visited[cur] = 1; // set state as visiting
    
    // traverse all the adjacent nodes
    for (auto neighbor : adj[cur]) {
      if (!dfs(neighbor, visited, adj)) {
        return false;
      }
    }
    
    // set state as visited
    visited[cur] = 2;
    return true;
  }
  
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      vector<vector<int> > adj(n);
      vector<int> visited(n, 0); // three states-> 0:unvisited, 1:visiting, 2:visited
      for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
      }
      bool tf = dfs(0, visited, adj);
      for (auto &v : visited) {
        if (!v) {
          return false;
        }
      }
      return tf;
    }
};
