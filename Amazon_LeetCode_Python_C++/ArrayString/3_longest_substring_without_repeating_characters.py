class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        mp = dict()
        l = 0
        for r in range(len(s)):
            if s[r] in mp:
                l = max(l, mp[s[r]])
            ans = max(ans, r - l + 1)
            mp[s[r]] = r + 1
        
        return ans
