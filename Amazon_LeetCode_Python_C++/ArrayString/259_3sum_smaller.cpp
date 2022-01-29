class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int lo = i + 1, hi = nums.size() - 1;
            int sum = 0;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum < target) {
                    ans += hi - lo;
                    lo++;
                }
                else {
                    hi--;
                }
            }
        }   
        return ans;
    }
};
