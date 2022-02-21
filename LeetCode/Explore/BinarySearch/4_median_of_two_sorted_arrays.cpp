class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums3;
    for (int i = 0; i < nums1.size(); i++) {
      nums3.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++) {
      nums3.push_back(nums2[i]);
    }
    sort(nums3.begin(), nums3.end());
    if (nums3.size() % 2) {
      return (double)nums3[nums3.size()/2];
    }
    else {
      return (double)(nums3[(nums3.size()/2) - 1] + nums3[nums3.size()/2])/2;
    }
  }
};
