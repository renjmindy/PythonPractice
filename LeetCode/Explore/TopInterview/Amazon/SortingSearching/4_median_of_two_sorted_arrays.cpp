class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int> vp = nums1;
      for (auto &num : nums2) {
        vp.push_back(num);
      }
      sort(vp.begin(), vp.end());
      if (vp.size() & 1) {
        return (double)vp[vp.size() / 2];
      }
      else {
        return (vp[(vp.size() / 2) - 1] + vp[vp.size() / 2]) * 0.5;
      }
    }
};
