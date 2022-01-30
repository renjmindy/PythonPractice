class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre = cur;
            cur = nums[i];
            if (cur == pre) {
                return cur;
            }
        }
        return -1;
    }
};
