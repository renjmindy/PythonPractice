// two pass hase set
// Time Complexity: \mathcal{O}(n^2)O(n2). twoSum is \mathcal{O}(n)O(n), and we call it nn times.
// Sorting the array takes \mathcal{O}(n\log{n})O(nlogn), so overall complexity is \mathcal{O}(n\log{n} + n^2)O(nlogn+n2). 
// This is asymptotically equivalent to \mathcal{O}(n^2)O(n2).
// Space Complexity: \mathcal{O}(n)O(n) for the hashset.

class Solution {

private:
  vector<vector<int> > ans;
  void twoSum(vector<int> &nums, int i, vector<vector<int> > &ans) {
    unordered_set<int> sp;
    for (int j = i + 1; j < nums.size(); j++) {
      int k = -(nums[i] + nums[j]);
      if (sp.count(k)) {
        ans.push_back({nums[i], nums[j], k});
        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
          j++;
        }
      }
      else {
        sp.insert(nums[j]);
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
