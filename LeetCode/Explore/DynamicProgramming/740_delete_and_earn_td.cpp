class Solution {
  
private:
  unordered_map<int, int> mp, dp;
  
  int dfs(int n) {
    if (n == 0) {
      dp[0] = 0;
    }
    else if (n == 1) {
      dp[1] = mp[1];
    }
    else {
      if (!dp.count(n)) {
        dp[n] = max(dfs(n - 1), dfs(n - 2) + mp[n]);
      }
    }
    return dp[n];
  }  
  
public:
  int deleteAndEarn(vector<int>& nums) {
    for (auto &num : nums) {
      mp[num] += num;
    } 
    return dfs(10001);
  }
};
