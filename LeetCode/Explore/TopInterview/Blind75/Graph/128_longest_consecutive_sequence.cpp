// Sorting

// Complexity Analysis
// Time complexity : O(nlgn)O(nlgn).
// The main for loop does constant work nn times, so the algorithm's time complexity is dominated by the invocation of sort, 
// which will run in O(nlgn)O(nlgn) time for any sensible implementation.
// Space complexity : O(1)O(1) (or O(n)O(n)).
// For the implementations provided here, the space complexity is constant because we sort the input array in place. 
// If we are not allowed to modify the input array, we must spend linear space to store a sorted copy.

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int longest = 1, current = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        if (nums[i] == nums[i - 1] + 1) {
          current++;
        }
        else {
          longest = max(longest, current);
          current = 1;
        }
      }
    }
    return max(longest, current);
  }
};
