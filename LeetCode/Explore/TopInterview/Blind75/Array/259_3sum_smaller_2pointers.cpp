// two pointers binary search
// Complexity analysis

// Time complexity: O(n^2 \log n)O(n2logn). The binarySearch function takes O(\log n)O(logn) time, therefore the twoSumSmaller takes O(n \log n)O(nlogn) time. 
// The threeSumSmaller wraps with another for-loop, and therefore is O(n^2 \log n)O(n2logn) time.
// Space complexity: O(1)O(1) because no additional data structures are used.

class Solution {
public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < target) {
          //cout << l << " " << r << endl;
          ans += r - l;
          l++;
        }  
        else {
          r--;
        }
      }
    }
    return ans;
  }
};
