class Solution {

public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    vector<int> dp(multipliers.size() + 1, 0);
    for (int i = multipliers.size() - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        dp[j] = max(dp[j] + multipliers[i] * nums[i - j], 
                    dp[j + 1] + multipliers[i] * nums[nums.size() - j - 1]); 
      }
    }
    return dp[0];  
  }
};
      
     
