// two pointers binary search
// Complexity Analysis
// Time Complexity: \mathcal{O}(n^2)O(n2). We have outer and inner loops, each going through nn elements.
// Sorting the array takes \mathcal{O}(n\log{n})O(nlogn), so overall complexity is \mathcal{O}(n\log{n} + n^2)O(nlogn+n2). 
// This is asymptotically equivalent to \mathcal{O}(n^2)O(n2).
// Space Complexity: from \mathcal{O}(\log{n})O(logn) to \mathcal{O}(n)O(n), depending on the implementation of the sorting algorithm.



class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int dif = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() && dif != 0; i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (abs(target - sum) < abs(dif)) {
          dif = target - sum;
        }
        if (sum < target) {
          l++;
        }
        else {
          r--;
        }
      }
    }
    return target - dif;
  }
};
