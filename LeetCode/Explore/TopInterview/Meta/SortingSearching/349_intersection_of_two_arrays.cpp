class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int, int> mp1, mp2;
      vector<int> ans;
      for (auto &num : nums1) {
        mp1[num]++;
      }
      for (auto &num : nums2) {
        if (mp1.count(num) && !mp2.count(num)) {
          mp2[num]++;
        }
      }
      for (auto &m : mp2) {
        ans.push_back(m.first);
      }
      return ans;
    }
};
