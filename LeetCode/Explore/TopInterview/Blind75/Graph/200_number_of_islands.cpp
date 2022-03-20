// DFS

// Complexity Analysis
// Time complexity : O(M \times N)O(M×N) where MM is the number of rows and NN is the number of columns.
// Space complexity : worst case O(M \times N)O(M×N) in case that the grid map is filled with lands where DFS goes by M \times NM×N deep.

class Solution {
  
private:
  void dfs(vector<vector<char> > &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) { // base case
      return;
    }
    
    // if visited already
    grid[i][j] = '0';
    
    // from north
    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
      dfs(grid, i - 1, j);
    }
    // from south
    if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
      dfs(grid, i + 1, j);
    }
    // from east
    if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') {
      dfs(grid, i, j + 1);
    }
    // from west
    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
      dfs(grid, i, j - 1);
    }
  }
  
public:
  int numIslands(vector<vector<char>>& grid) {
    int numIslands = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          numIslands++;
        }
      }
    }
    return numIslands;
  }
};
