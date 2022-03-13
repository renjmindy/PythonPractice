// one pass hash table
// Complexity Analysis
// Time complexity: O(n)O(n). We do search() and insert() for nn times and each operation takes constant time.
// Space complexity: O(n)O(n). The space used by a hash table is linear with the number of elements in it.
  
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> sp;
    for (auto &num : nums) {
      if (sp.count(num)) {
        return true;
      }
      else {
        sp.insert(num);
      }
    }
    return false;
  }
};

[Problem 219 Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/)
[Problem 220 Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)
