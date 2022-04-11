class Solution {
  
private:
  bool dfs(int curr, vector<int> &vis1, vector<int> &vis2, vector<vector<int> > &graph) {
    vis1[curr] = 1;
    vis2[curr] = 1;
    for (int i = 0; i < graph[curr].size(); i++) {
      if (vis1[graph[curr][i]] == 0) {
        if (dfs(graph[curr][i], vis1, vis2, graph)) {
          return true;
        }
      }
      else if (vis2[graph[curr][i]] == 1) {
        return true;
      }
    }
    vis2[curr] = 0;
    return false;
  }
  
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int> > graph(numCourses);
      vector<int> vis1(numCourses, 0);
      vector<int> vis2(numCourses, 0);
      for (int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
      }
      for (int i = 0; i < numCourses; i++) {
        if (vis1[i] == 0) {
          if (dfs(i, vis1, vis2, graph)) {
            return false;
          }
        }
      }
      return true;
    }
};
