class Solution {
  
private:
  int dfs(int z, vector<int> &visited, vector<vector<int> > &edges) {
    if (visited[z]) {
      return 0;
    }
    visited[z] = 1;
    int ans = 1;
    for (auto &i : edges[z]) {
      ans += dfs(i, visited, edges);
    }
    return ans;
  }
  
public:
    int removeStones(vector<vector<int>>& stones) {
      int ans = 0;
      vector<int> visited(stones.size(), 0);
      vector<vector<int> > edges(stones.size(), vector<int>());
      for (int i = 0; i < stones.size(); i++) {
        for (int j = i + 1; j < stones.size(); j++) {
          if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
            edges[i].push_back(j);
            edges[j].push_back(i);
          }
        }
      }
      for (int i = 0; i < stones.size(); i++) {
        if (!visited[i]) {
          ans += (dfs(i, visited, edges) - 1);
        }
      }
      return ans;
    }
};
