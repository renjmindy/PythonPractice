// two pointers
// Complexity Analysis
// Time Complexity: \mathcal{O}(n^2)O(n2). twoSumII is \mathcal{O}(n)O(n), and we call it nn times.
// Sorting the array takes \mathcal{O}(n\log{n})O(nlogn), so overall complexity is \mathcal{O}(n\log{n} + n^2)O(nlogn+n2). 
// This is asymptotically equivalent to \mathcal{O}(n^2)O(n2).
// Space Complexity: from \mathcal{O}(\log{n})O(logn) to \mathcal{O}(n)O(n), depending on the implementation of the sorting algorithm. 
// For the purpose of complexity analysis, we ignore the memory required for the output.

class Solution {

private:
  vector<vector<int> > ans;
  void twoSum(vector<int> &nums, int i, vector<vector<int> > &ans) {
    int l = i + 1, r = nums.size() - 1;
    while (l < r) {
      int sum = nums[i] + nums[l] + nums[r];
      if (sum < 0) {
        l++;
      }
      else if (sum > 0) {
        r--;
      }
      else {
        ans.push_back({nums[i], nums[l], nums[r]});
        l++;
        r--;
        while (l < r && nums[l - 1] == nums[l]) {
          l++;
        }
      }
    }
  }
  
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
      if (i == 0 || nums[i - 1] != nums[i]) {
        twoSum(nums, i, ans);
      }
    }
    return ans;
  }
};
