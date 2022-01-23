class Solution:
    def frequencySort(self, s: str) -> str:
        sd = Counter(s)
        t = list()
        for c in sorted(sd, key=sd.get, reverse=True):
            for i in range(sd[c]):
                t.append(c)
        return ''.join(t)  
