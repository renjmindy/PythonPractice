class Solution {
public:
    bool isAnagram(string s, string t) {
        int countS[26], countT[26];
        memset(countS, 0, sizeof(countS));
        memset(countT, 0, sizeof(countT));
        for (int i = 0; i < s.size(); i++) {
            countS[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            countT[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (countS[i] != countT[i]) {
                return false;
            }
        }
        return true;
    }
};
