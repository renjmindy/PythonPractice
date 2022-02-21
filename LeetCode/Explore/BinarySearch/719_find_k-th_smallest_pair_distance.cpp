class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      int pivot, l = 0, r = nums[nums.size() - 1] - nums[0];
      while (l < r) {
        pivot = l + (r - l) / 2;
        int count = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
          while (nums[right] - nums[left] > pivot) {
            left++;
          }
          count += right - left;
        }
        if (count >= k) {
          r = pivot;
        }
        else {
          l = pivot + 1;
        }
      }
      return l;
    }
};
