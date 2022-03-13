// one pass hash table 
// Complexity Analysis
// Time complexity: O(n)O(n). We traverse the list containing nn elements only once. Each lookup in the table costs only O(1)O(1) time.
// Space complexity: O(n)O(n). The extra space required depends on the number of items stored in the hash table, which stores at most nn elements.
  
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (mp.count(target - nums[i])) {
        ans.push_back(mp[target - nums[i]]);
        ans.push_back(i);
      }
      mp[nums[i]] = i;
    }
    return ans;
  }
};
