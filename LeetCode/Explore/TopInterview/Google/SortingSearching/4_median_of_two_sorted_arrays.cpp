class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      for (auto &num : nums2) {
        nums1.push_back(num);
      }
      sort(nums1.begin(), nums1.end());
      if (nums1.size() & 1) {
        return (double)nums1[nums1.size()/2];
      }
      else {
        return 0.5*(nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1]);
      }
    }
};
