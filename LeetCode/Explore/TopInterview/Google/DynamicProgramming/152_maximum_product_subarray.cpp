class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int maxProd = nums[0], curMax = nums[0], curMin = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        int tmpProd = max(nums[i], max(curMax * nums[i], curMin * nums[i]));
        curMin = min(nums[i], min(curMax * nums[i], curMin * nums[i]));
        curMax = tmpProd;
        maxProd = max(maxProd, curMax);
      }
      return maxProd;
    }
};
