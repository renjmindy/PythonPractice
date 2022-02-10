class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 0 || !count(nums.begin(), nums.end(), 1)) {
            return 0;
        }
        int count = 0, maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            }
            else {
                maxVal = max(maxVal, count);
                count = 0;
            }
        }
        return max(maxVal, count);
    }
};
