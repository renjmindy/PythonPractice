class Solution:
    def removeVowels(self, s: str) -> str:
        t = list()
        v = ['a', 'e', 'i', 'o', 'u']
        for i, c in enumerate(s):
            if c.lower() not in v:
                t.append(c)
                
        return ''.join(t)
