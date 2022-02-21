class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int, int> mp;
      for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i])) {
          return nums[i];
        }
        mp[nums[i]]++;
      }
      return -1;
    }
};
