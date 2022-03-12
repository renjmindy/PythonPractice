class Solution {
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    // If we cannot schedule at least one job per day, 
    // it is impossible to create a schedule
    if (jobDifficulty.size() < d) {
      return -1;
    }
    vector<vector<int> > dp(jobDifficulty.size(), vector<int>(d + 1, INT_MAX));
    
    // Set base cases
    dp[jobDifficulty.size() - 1][d] = jobDifficulty[jobDifficulty.size() - 1];
    
    // On the last day, we must schedule all remaining jobs, so dp[i][d]
    // is the maximum difficulty job remaining
    for (int i = jobDifficulty.size() - 2; i >= 0; i--) {
      dp[i][d] = max(dp[i + 1][d], jobDifficulty[i]);
    }
    
    for (int day = d - 1; day > 0; day--) {
      for (int i = day - 1; i < jobDifficulty.size() - (d - day); i++) {
        int hardest = 0;
        // Iterate through the options and choose the best
        for (int j = i; j < jobDifficulty.size() - (d - day); j++) {
          hardest = max(hardest, jobDifficulty[j]);
          // Recurrence relation
          dp[i][day] = min(dp[i][day], hardest + dp[j + 1][day + 1]);
        }
      }
    }
    return dp[0][1];
  }
};
