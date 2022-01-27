class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() < k + 1) {
            return s.size();
        }
        unordered_map<char, int> mp;
        int max_len = k;
        for (int r = 0, l = 0; r < s.size(); r++) {
            mp[s[r]] = r;
            if (mp.size() == k + 1) {
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
