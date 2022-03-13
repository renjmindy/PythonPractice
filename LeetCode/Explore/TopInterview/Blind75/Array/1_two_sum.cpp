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

[1099. Two Sum Less Than K](https://leetcode.com/problems/two-sum-less-than-k/)
[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
[170. Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/)                            
[653. Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
[15. 3Sum](https://leetcode.com/problems/3sum/)
[16. 3Sum Closest](https://leetcode.com/problems/3sum-closest/)
[923. 3Sum With Multiplicity](https://leetcode.com/problems/3sum-with-multiplicity/)
[18. 4Sum](https://leetcode.com/problems/4sum/)
[454. 4Sum II](https://leetcode.com/problems/4sum-ii/)
