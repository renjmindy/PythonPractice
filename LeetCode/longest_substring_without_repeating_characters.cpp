class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int ans = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            if (mp.find(s[r]) != mp.end()) {
                l = max(mp[s[r]], l);
            }
            ans = max(ans, r - l + 1);
            mp[s[r]] = r + 1;
        }
        return ans;
    }
};
