// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Given NN as the length of nums, Time complexity: O(N^2)O(N2) 
// We use two nested for loops resulting in 
// 1 + 2 + 3 + 4 + ... + N = \dfrac {N * (N + 1)}{2}1+2+3+4+...+N=2N∗(N+1)​operations, resulting in a time complexity of O(N^2)O(N2).
// Space complexity: O(N)O(N) The only extra space we use relative to input size is the dp array, which is the same length as nums.

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1); 
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
