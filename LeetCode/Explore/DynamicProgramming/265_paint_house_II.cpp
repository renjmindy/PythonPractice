class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.size() == 0) {
      return 0;
    }
    for (int h = costs.size() - 2; h >= 0; h--) {
      for (int c = 0; c < costs[0].size(); c++) {
        int minVal = INT_MAX;
        for (int pc = 0; pc < costs[0].size(); pc++) {
          if (c == pc) {
            continue;
          }
          minVal = min(minVal, costs[h + 1][pc]);
        }
        costs[h][c] += minVal;
      }
    }
    int minVal = INT_MAX;
    for (auto &c : costs[0]) {
      minVal = min(minVal, c);
    }
    return minVal;
  }
};
