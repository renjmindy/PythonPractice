class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp1(nums.size());
        vector<int> dp2(nums.size());
        dp1[0] = dp2[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp1.at(i) = max(nums.at(i), dp1.at(i-1) + nums.at(i));
            dp2.at(i) = max(dp2.at(i-1), dp1.at(i));
        }
        return dp2.back();
    }
};

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        maxSum = nums[0]
        maxTillNow = nums[0]
        
        for i in range(1, len(nums), 1):
            
            maxTillNow = max(maxTillNow + nums[i], nums[i])
            maxSum = max(maxTillNow, maxSum)
            
        return maxSum
