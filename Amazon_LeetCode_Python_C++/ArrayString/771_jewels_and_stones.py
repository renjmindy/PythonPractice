class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        j = list(jewels)
        s = list(stones)
        ans  = 0
        for i, c in enumerate(stones):
            if c in j:
                ans += 1
                
        return ans
