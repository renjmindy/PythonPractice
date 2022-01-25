class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', ']':'[', '}':'{'};
        sp = []
        
        for i, c in enumerate(s):
            if c not in mp:
                sp.append(c)
            else:
                if len(sp) == 0 or mp[c] != sp[-1]:
                    return False
                sp.pop()
                
        return len(sp) == 0
