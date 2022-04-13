class Solution {
  
private:
  bool dfs(int curr, vector<int> &visited, vector<vector<int> > &adj) {
    if (visited[curr] == 2) {
      return true;
    }
    visited[curr] = 2;
    
    for (int i = 0; i < adj[curr].size(); i++) {
      if (visited[adj[curr][i]] != 1 && dfs(adj[curr][i], visited, adj)) {
        return true;
      }
    }
    visited[curr] = 1;
    return false;
  }
  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int> > adj(numCourses);
      vector<int> visited(numCourses, 0);
      for (int i = 0; i < prerequisites.size(); i++) {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
      }
      for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
          if (dfs(i, visited, adj)) {
            return false;
          }
        } 
      }
      return true;
    }
};
