class Solution:
    def reverseVowels(self, s: str) -> str:
        v = []
        t = ['a', 'e', 'i', 'o', 'u']
        for i in range(len(s)):
            if s[i].lower() in t:
                v.append(i)
        
        s = list(s)
        l, r = 0, len(v) - 1
        while l < r:
            s[v[l]], s[v[r]] = s[v[r]], s[v[l]]
            l += 1
            r -= 1
        
        return ''.join(s)
