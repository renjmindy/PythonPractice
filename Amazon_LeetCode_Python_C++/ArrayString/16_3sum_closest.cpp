class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size() && diff != 0; i++) {
            int lo = i + 1, hi = nums.size() - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }
        return target - diff;
    }
};
