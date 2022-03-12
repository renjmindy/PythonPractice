class Solution {
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    const int MAX_COST = 1000001;
    vector<vector<vector<int> > > dp(m, vector<vector<int> >(target + 1, vector<int>(n, MAX_COST)));
    // Initialize for house 0, neighborhoods will be 1
    for (int c = 1; c <= n; c++) {
      if (houses[0] == c) {
        // If the house has same color, no cost
        dp[0][1][c - 1] = 0;
      }
      else if (!houses[0]) {
        // If the house is not painted, assign the corresponding cost
        dp[0][1][c - 1] = cost[0][c - 1];
      }
    }
    
    for (int h = 1; h < m; h++) {
      for (int neighbors = 1; neighbors <= min(target, h + 1); neighbors++) {
        for (int c = 1; c <= n; c++) {
          // If the house is already painted, and color is different
          if (houses[h] && c != houses[h]) {
            // Cannot be painted with different color
            continue;
          }
          int currCost = INT_MAX;
          // Iterate over all the possible color for previous house
          for (int pc = 1; pc <= n; pc++) {
            if (pc != c) {
              // Decrement the neighborhood as adjacent houses has different color
              currCost = min(currCost, dp[h - 1][neighbors - 1][pc - 1]);
            }
            else {
              // Previous house has the same color, no change in neighborhood count
              currCost = min(currCost, dp[h - 1][neighbors][c - 1]);
            }
          }
          // If the house is already painted cost to paint is 0
          int costPaint = houses[h] ? 0 : cost[h][c - 1];
          dp[h][neighbors][c - 1] = currCost + costPaint;
        }
      }
    }
    int minCost = MAX_COST;
    // Find the minimum cost with m houses and target neighborhoods
    // By comparing cost for different color for the last house
    for (int c = 1; c <= n; c++) {
      minCost = min(minCost, dp[m - 1][target][c - 1]);
    }
    // Return -1 if the answer is MAX_COST as it implies no answer possible
    return minCost == MAX_COST ? -1 : minCost;
  }
};
