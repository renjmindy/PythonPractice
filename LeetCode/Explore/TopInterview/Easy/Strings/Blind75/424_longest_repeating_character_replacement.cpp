class Solution {
  
private:
  unordered_map<char, int> mp;
  
public:
  int characterReplacement(string s, int k) {
    int count = 0, ans = 0;
    for (int r = 0, l = 0; r < s.size(); r++) {
      mp[s[r]]++;
      count = max(count, mp[s[r]]);
      if (r - l + 1 - count > k) {
        mp[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
