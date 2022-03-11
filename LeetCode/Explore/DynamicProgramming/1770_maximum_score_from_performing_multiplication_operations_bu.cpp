class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int numsLen = nums.size(), multLen = multipliers.size();
        
        // dp[multIdx][numsLeftIdx] is the maximum score after multIdx operations have been done
        // and numsLeftIdx leftmost elements have been taken from nums.
        vector<vector<int>> dp(multLen + 1, vector<int>(multLen + 1, 0));
        
        for (int multIdx = multLen - 1; multIdx >= 0; --multIdx) {
            for (int numsLeftIdx = multIdx; numsLeftIdx >= 0; --numsLeftIdx) {
                int numsRightIdx = numsLen - 1 - (multIdx - numsLeftIdx);
                    
                // In each operation, we have two choices to maximize our score.

                // choice 1
                // Pick the leftmost element of nums.
                // Then, our score would be multipliers[multIdx] * nums[numsLeftIdx] + dp[multIdx + 1][numsLeftIdx + 1]

                // choice 2
                // Pick the rightmost element of nums.
                // Then, our score would be multipliers[multIdx] * nums[numsRightIdx] + dp[multIdx + 1][numsLeftIdx]

                // To maximize our score, choose the case contributing higher score.
                dp[multIdx][numsLeftIdx] = 
                    max(multipliers[multIdx] * nums[numsLeftIdx] + dp[multIdx + 1][numsLeftIdx + 1],
                        multipliers[multIdx] * nums[numsRightIdx] + dp[multIdx + 1][numsLeftIdx]);
            } // end of for-loop
        } // end of for-loop
        
        return dp[0][0];
    }
};
