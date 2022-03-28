class Solution {
public:
    int maxArea(vector<int>& height) {
      int maxArea = INT_MIN, l = 0, r = height.size() - 1;
      while (l < r) {
        maxArea = max(maxArea, (r - l) * min(height[l], height[r]));
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
