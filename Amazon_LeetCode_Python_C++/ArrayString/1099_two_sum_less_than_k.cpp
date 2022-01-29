class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum_max = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int lo = i + 1, hi = nums.size() - 1;
            while (lo <= hi) {
                int sum = nums[i] + nums[lo];
                if (sum > sum_max && sum < k) {
                    sum_max = sum;
                }
                lo++;
            } 
        }
        return sum_max > 0 ? sum_max : -1;
    }
};
