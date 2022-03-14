// two pointers sliding window hash table
// Complexity Analysis
// Time Complexity: O(|S|)O(∣S∣) where |S| represents the length of string SS. 
// In the worst case we might end up visiting every element of string SS twice, once by left pointer and once by right pointer. 
// Space Complexity: O(|S|)O(∣S∣). |S|∣S∣ when the window size is equal to the entire string SS. 

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int count = 0, ans = 0;
    for (int r = 0, l = 0; r < s.size(); r++) {
      mp[s[r]]++;
      count = max(count, mp[s[r]]);
      // when repeating counts are too small to get one longest repeating string
      // sliding window shifts towards right 
      if (r - l + 1 - count > k) {
        mp[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
