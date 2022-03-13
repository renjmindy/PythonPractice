// two pass binary search maximal area
// Complexity Analysis
// Time complexity : O(n)O(n). Single pass.
// Space complexity : O(1)O(1). Constant space is used.

class Solution {
public:
  int maxArea(vector<int>& height) {
    int maxArea = INT_MIN, l = 0, r = height.size() - 1;
    while (l < r) {
      maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        l++;
      }
      else {
        r--;
      }
    }
    return maxArea;
  }
};
