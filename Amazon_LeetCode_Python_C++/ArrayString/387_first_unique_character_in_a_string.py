class Solution:
    def firstUniqChar(self, s: str) -> int:
        sd = Counter(s)
        for i, c in enumerate(s):
            if sd[c] == 1:
                return i
        return -1
