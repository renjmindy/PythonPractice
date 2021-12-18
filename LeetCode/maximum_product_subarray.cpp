class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dpMax(nums), dpMin(nums);
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dpMax.at(i) = max(nums.at(i), nums.at(i)*(nums.at(i) >= 0 ? dpMax.at(i-1) : dpMin.at(i-1)));
            dpMin.at(i) = min(nums.at(i), nums.at(i)*(nums.at(i) >= 0 ? dpMin.at(i-1) : dpMax.at(i-1)));
            ans = max(ans, dpMax.at(i));
        }
        return ans;
    }
};
