class Solution {

private:
  int ans = 0;
  set<int> sp;
  
  int dfs(int n, vector<int> &costs, vector<int> &dp) {
    if (n > 365) {
      return 0;
    }
    if (dp[n] > 0) {
      return dp[n];
    }
    if (sp.count(n)) {
      ans = min(min(dfs(n + 1, costs, dp) + costs[0], dfs(n + 7, costs, dp) + costs[1]), dfs(n + 30, costs, dp) + costs[2]);
    }
    else {
      ans = dfs(n + 1, costs, dp);
    }
    dp[n] = ans;
    return ans;
  }
  
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366, 0);
    for (auto &day : days) {
      sp.insert(day);
    }
    return dfs(1, costs, dp);
  }
};
