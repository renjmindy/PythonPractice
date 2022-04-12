class Solution {
  
private:
  void dfs(int cur, vector<bool> &visited, vector<vector<int> > &adj) {
    for (int i = 0; i < isConnected[cur].size(); i++) {
      if (isConnected[cur][i] && !visited[i]) {
        visited[i] = true;
        dfs(i, visited, adj);
      }
    }
  }
  
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      vector<bool> visited(isConnected.size(), false);
      int ans = 0;
      for (int i = 0; i < isConnected.size(); i++) {
        if (!visited[i]) {
          dfs(i, visited, isConnected);
          ans++;
        }
      }
      return ans;
    }
};
