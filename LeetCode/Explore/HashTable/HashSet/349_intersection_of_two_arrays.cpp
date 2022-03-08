class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> sp1, sp2;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
      if (!sp1.count(nums1[i])) {
        sp1.insert(nums1[i]);
      }
    }
    for (int i = 0; i < nums2.size(); i++) {
      if (sp1.count(nums2[i]) && !sp2.count(nums2[i])) {
        ans.push_back(nums2[i]);
        sp2.insert(nums2[i]);
      }
      else {
        continue;
      }
    }
    return ans;
  }
};
