class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) {
            return s.size();
        }
        unordered_map<char, int> mp;
        int max_len = 2, ans = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            mp[s[r]] = r;
            if (mp.size() == 3) {
                int del_idx = s.size() - 1;
                for (auto &m : mp) {
                    del_idx = min(del_idx, m.second);
                }
                mp.erase(s[del_idx]);
                l = del_idx + 1;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
