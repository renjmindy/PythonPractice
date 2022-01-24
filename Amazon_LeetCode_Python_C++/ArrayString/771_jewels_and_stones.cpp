class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        set<char> sj;
        for (int i = 0; i < jewels.size(); i++) {
            if (!sj.count(jewels[i])) {
                sj.insert(jewels[i]);
            }
        }
        for (int i = 0; i < stones.size(); i++) {
            if (sj.count(stones[i])) {
                ans += 1;
            }
        }
        return ans;
    }
};
