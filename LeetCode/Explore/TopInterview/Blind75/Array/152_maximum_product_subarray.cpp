// one pass dynamical programming, Kadane's Algorithm
// Complexity Analysis
// Time complexity : O(N)O(N) where NN is the size of nums. 
// The algorithm achieves linear runtime since we are going through nums only once.
// Space complexity : O(1)O(1) since no additional space is consumed rather than 
// variables which keep track of the maximum product so far, the minimum product so far, 
// current variable, temp variable, and placeholder variable for the result.

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], curMax = nums[0], curMin = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int tmpMax = max(nums[i], max(curMax * nums[i], curMin * nums[i]));
      curMin = min(nums[i], min(curMax * nums[i], curMin * nums[i]));
      curMax = tmpMax;
      maxProd = max(maxProd, curMax);
    }
    return maxProd;
  }
};
