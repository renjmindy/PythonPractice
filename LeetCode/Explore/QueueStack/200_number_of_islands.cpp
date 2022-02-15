class Solution {
  
private:
  void dfs(int r, int c, vector<vector<char> > &grid) {
    int nr = grid.size(), nc = grid[0].size();
    
    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r-1][c] == '1') {
      dfs(r - 1, c, grid);
    }
    if (r + 1 < nr && grid[r+1][c] == '1') {
      dfs(r + 1, c, grid);
    }
    if (c - 1 >= 0 && grid[r][c-1] == '1') {
      dfs(r, c - 1, grid);
    }
    if (c + 1 < nc && grid[r][c+1] == '1') {
      dfs(r, c + 1, grid);
    }
  }
  
public:
    int numIslands(vector<vector<char>>& grid) {
      int nr = grid.size(), nc = grid[0].size(), numIslands = 0;
      if (!nr) {
        return 0;
      }
      for (int r = 0; r < nr; r++) {
        for (int c = 0; c < nc; c++) {
          if (grid[r][c] == '1') {
            numIslands++;
            dfs(r, c, grid);
          }
        }
      }
      return numIslands;
    }
};
