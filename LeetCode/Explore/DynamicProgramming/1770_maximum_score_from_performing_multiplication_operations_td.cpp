class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        numsLen = nums.size();
        multLen = multipliers.size();
        
        // memo[multIdx][numsLeftIdx] is the max score, after multIdx operations
        // have been done and numsLeftIdx leftmost elements have been taken from
        // nums.
        vector<vector<int>> memo(multLen, vector<int>(multLen, 0));
        
        dp(nums, multipliers, memo, 0, 0);
        
        return memo[0][0];
    }
    
private:
    int numsLen;
    int multLen;
    
    // dp(multIdx, numsLeftIdx) returns the max score, after multIdx operatons
    // have been done and numsLeftIdx leftmost elements have been taken from
    // nums.
    int dp(vector<int>& nums, vector<int>& multipliers, vector<vector<int>>& memo, int multIdx, int numsLeftIdx) {
        if (multIdx == multipliers.size()) {
            // base case
            // When all the multipliers are used, no more score can be added.
            return 0;
        }
        
        if (memo[multIdx][numsLeftIdx] == 0) {
            // (multIdx - numsLeftIdx) is the number of rightmost elements taken from nums.
            // Therefore, numsRightIdx = numsLen - 1 - (multIdx - numsLeftIdx)
            int numsRightIdx = numsLen - 1 - (multIdx - numsLeftIdx);
            
            // In each operation, we have two choices to maximize our score.

            // choice 1
            // Pick the leftmost element of nums.
            // Then, our score would be multipliers[multIdx] * nums[numsLeftIdx] + dp(multIdx + 1, numsLeftIdx + 1)

            // choice 2
            // Pick the rightmost element of nums.
            // Then, our score would be multipliers[multIdx] * nums[numsRightIdx] + dp(memo, multIdx + 1, numsLeftIdx)

            // To maximize our score, choose the case contributing higher score.
            memo[multIdx][numsLeftIdx] =
                max(multipliers[multIdx] * nums[numsLeftIdx] + dp(nums, multipliers, memo, multIdx + 1, numsLeftIdx + 1), 
                    multipliers[multIdx] * nums[numsRightIdx] + dp(nums, multipliers, memo, multIdx + 1, numsLeftIdx));
        }
        
        return memo[multIdx][numsLeftIdx];
    }
};
