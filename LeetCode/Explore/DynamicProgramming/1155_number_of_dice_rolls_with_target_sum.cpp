class Solution {
public:
  int numRollsToTarget(int n, int k, int target) {
    int mod = 1e9 + 7;
    vector<vector<int>> dp(30001 , vector<int>(n + 1));
    
    dp[target][0] = 1;
	  for(int count = 1; count <= n ; count++) {
		  for(int sum = target; sum >= 0; sum--) {
			  int ways = 0;
			  for(int face = 1; face <= k; face++) {
				  ways = (ways + dp[sum + face][count - 1]) % mod;
			  }
			  dp[sum][count] = ways;
		  }
	  }
	  return dp[0][n];     
  }
};
