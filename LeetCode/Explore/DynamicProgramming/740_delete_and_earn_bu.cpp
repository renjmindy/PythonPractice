class Solution {
  
public:
  int deleteAndEarn(vector<int>& nums) {
    unordered_map<int, int> mp;
    vector<int> dp(10001, 0);
    
    for (auto &num : nums) {
      mp[num] += num;
    }
    
    dp[0] = 0;
    dp[1] = mp[1];
    for (int i = 2; i < 10001; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + mp[i]);
    }
    return dp[10000];
  }
};
