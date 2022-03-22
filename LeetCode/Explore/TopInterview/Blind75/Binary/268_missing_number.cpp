// Sorting

// Complexity Analysis
// Time complexity : \mathcal{O}(nlgn)O(nlgn)
// The only elements of the algorithm that have asymptotically nonconstant time complexity are the main for loop (which runs in \mathcal{O}(n)O(n) time), 
// and the sort invocation (which runs in \mathcal{O}(nlgn)O(nlgn) time for Python and Java). Therefore, the runtime is dominated by sort, 
// and the entire runtime is \mathcal{O}(nlgn)O(nlgn).
// Space complexity : \mathcal{O}(1)O(1) (or \mathcal{O}(n)O(n))
// In the sample code, we sorted nums in place, allowing us to avoid allocating additional space. If modifying nums is forbidden, we can allocate 
// an \mathcal{O}(n)O(n) size copy and sort that instead.

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (i != nums[i]) {
        return i;
      }
    }
    return nums.size();
  }
};
