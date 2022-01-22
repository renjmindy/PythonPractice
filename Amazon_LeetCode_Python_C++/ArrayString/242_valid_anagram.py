class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if set(s) != set(t):
            return set(s) == set(t)
        
        return Counter(s) == Counter(t)
            
