class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums1.size(); i++) {
      mp[nums1[i]]++;
    }
    for (int i = 0; i < nums2.size(); i++) {
      if (mp[nums2[i]] > 1) {
        vector<int>::iterator it = find(ans.begin(), ans.end(), nums2[i]);
        if (it == ans.end()) {
          ans.push_back(nums2[i]);
          mp[nums2[i]]--;
        }
      }
      else if (mp[nums2[i]] == 1) {
        vector<int>::iterator it = find(ans.begin(), ans.end(), nums2[i]);
        if (it == ans.end()) {
          ans.push_back(nums2[i]);
          mp.erase(nums2[i]);
        }
      }
      else {
        continue;
      }
    }
    return ans;
  }
};
