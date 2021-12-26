class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> mp;
        for (auto c : s) {
            mp[c]++;
        }
        for (auto c : t) {
            if (mp.find(c) != mp.end()) {
                if (mp[c] > 1) {
                    mp[c]--;
                }
                else {
                    mp.erase(c);
                }
            }
            else {
                return false;
            }
        }
        return mp.empty() == true;
    }
};
