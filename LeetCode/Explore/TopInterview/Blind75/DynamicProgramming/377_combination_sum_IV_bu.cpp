// dynamical programming: bottom-up tabulation

// Complexity Analysis
// Let TT be the target value, and NN be the number of elements in the input array.
// Time Complexity: \mathcal{O}(T \cdot N)O(T⋅N)
// We have a nested loop, with the number of iterations as TT and NN respectively.
// Hence, the overall time complexity of the algorithm is \mathcal{O}(T \cdot N)O(T⋅N).
// Space Complexity: \mathcal{O}(T)O(T)
// We allocate an array dp[i] to hold all the intermediate values, which amounts to \mathcal{O}(T)O(T) space.

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0); // similar to total amount of money
    sort(nums.begin(), nums.end()); // similar to an array of different coins
    dp[0] = 1;
    for (int i = 1; i < target + 1; i++) {
      for (auto &num : nums) {
        if (num <= i) {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};
