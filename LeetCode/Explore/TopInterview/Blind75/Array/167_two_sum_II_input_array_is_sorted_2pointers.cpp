// two pointers binary search
// Complexity Analysis
// Time complexity: O(n)O(n). The input array is traversed at most once. Thus the time complexity is O(n)O(n).
// Space complexity: O(1)O(1). We only use additional space to store two indices and the sum, so the space complexity is O(1)O(1).

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int pivot, l = 0, r = numbers.size() - 1;
    while (l < r) {
      int sum = numbers[l] + numbers[r];
      if (sum < target) {
        l++;
      }
      else if (sum > target) {
        r--;
      }
      else {
        return {l + 1, r + 1};
      }
    }
    return {-1, -1};
  }
};
