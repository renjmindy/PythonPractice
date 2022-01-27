class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1), dpl(nums.size()), dpr(nums.size());
        dpl[0] = nums[0];
        dpr[nums.size() - 1] = nums[nums.size() - 1];
        for (int l = 1; l < nums.size(); l++) {
            if (l % k == 0) {
                dpl[l] = nums[l];
            }
            else {
                dpl[l] = max(dpl[l - 1], nums[l]);
            }
            int r = nums.size() - 1 - l;
            if ((r + 1) % k == 0) {
                dpr[r] = nums[r];
            }
            else {
                dpr[r] = max(dpr[r + 1], nums[r]);
            }
        }
        for (int i = 0; i < nums.size() - k + 1; i++) {
            ans[i] = max(dpl[i + k - 1], dpr[i]);
        }
        return ans;
    }
};
