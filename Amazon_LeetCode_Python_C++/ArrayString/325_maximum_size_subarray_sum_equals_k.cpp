class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, max_len = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                max_len = i + 1;
            }
            if (mp.find(sum - k) != mp.end()) {
                max_len = max(max_len, i - mp[sum - k]);
            }
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        return max_len;
    }
};
