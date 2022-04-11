// DFS

// Complexity Analysis
// Time complexity: O(M \cdot N)O(M⋅N), where MM is the number of rows and NN is the number of columns.
// Similar to approach 1. The dfs function runs exactly once for each cell accessible from an ocean.
// Space complexity: O(M \cdot N)O(M⋅N), where MM is the number of rows and NN is the number of columns.
// Similar to approach 1. Space that was used by our queues is now occupied by dfs calls on the recursion stack.

class Solution {
  
private:
  vector<vector<int> > ans;
  
  void dfs(vector<vector<int> > &heights, int i, int j, int pre, vector<vector<bool> > &ocean) {
    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) { // base case
      return;
    }
    
    // water only flows from higher cell
    if (heights[i][j] < pre) {
      return;
    }
    
    // if already visited
    if (ocean[i][j]) {
      return;
    }
    
    // label visited already
    ocean[i][j] = true;
    
    // from south
    dfs(heights, i - 1, j, heights[i][j], ocean);
    // from north
    dfs(heights, i + 1, j, heights[i][j], ocean);
    // from west
    dfs(heights, i, j + 1, heights[i][j], ocean);
    // from east
    dfs(heights, i, j - 1, heights[i][j], ocean);
    
  }
  
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    // 2D matrix for pacific & atlantic oceans
    vector<vector<bool> > pacific(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool> > atlantic(heights.size(), vector<bool>(heights[0].size(), false));
    
    // updated pacific and atlantic matrix from which water can flow to respective oceans
    for (int i = 0; i < heights.size(); i++) {
      dfs(heights, i, 0, INT_MIN, pacific); // first column
      dfs(heights, i, heights[0].size() - 1, INT_MIN, atlantic); // last column
    }
    for (int j = 0; j < heights[0].size(); j++) {
      dfs(heights, 0, j, INT_MIN, pacific); // first row
      dfs(heights, heights.size() - 1, j, INT_MIN, atlantic); // last row
    }
    
    // intersection of pacific and atlantic matrix
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};
