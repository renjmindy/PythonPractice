class Solution:
    def reverseWord(self, s: list, left: int, right: int) -> None:
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
    
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        r = l = 0
        s.reverse()
        while r < len(s):
            while l < len(s) and s[l] != ' ':
                l += 1
            self.reverseWord(s, r, l - 1)
            l += 1
            r = l
