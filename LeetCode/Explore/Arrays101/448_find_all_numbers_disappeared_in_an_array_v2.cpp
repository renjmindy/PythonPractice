class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      //int i = *max_element(nums.begin(), nums.end());
      int i = nums.size();
      sort(nums.begin(), nums.end());
      unordered_map<int, bool> mp;
      vector<int> ans;
      for (int j = 0; j < i; j++) {
        mp[nums.at(j)] = true;
      }
      for (int j = 1; j <= i; j++) {
        if (!mp[j]) {
          ans.push_back(j);
        }
      }
      return ans;
    }
};
