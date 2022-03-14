// two pointers sliding window hash table
// Complexity Analysis
// Time Complexity: O(|S| + |T|)O(∣S∣+∣T∣) where |S| and |T| represent the lengths of strings SS and TT. 
// In the worst case we might end up visiting every element of string SS twice, once by left pointer and once by right pointer. 
// |T|∣T∣ represents the length of string TT.
// Space Complexity: O(|S| + |T|)O(∣S∣+∣T∣). |S|∣S∣ when the window size is equal to the entire string SS. |T|∣T∣ when TT has all unique characters.

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    int count = 0;
    string ans;
    for (auto &c : t) {
      mp[c]++;
    }
    for (int r = 0, l = 0; r < s.size() && l < s.size(); r++) {
      if (mp[s[r]] > 0) { // match s to t
        count++;
      }
      mp[s[r]]--;
      if (count < t.size()) {
        continue;
      }
      // when reaching to t's size
      while (l < s.size() && mp[s[l]] < 0) { // only count distinct letters surrounding by characters existing in both s & t
        mp[s[l]]++;
        l++;
      }
      if (ans.empty() || r - l + 1 < ans.size()) {
        ans = s.substr(l, r - l + 1); // find minimal string window 
      }
    }
    return ans;
  }
};
