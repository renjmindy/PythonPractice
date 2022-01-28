class Solution {
public:
    int minSteps(string s, string t) {
        int ans = 0, countws[26];
        memset(countws, 0, sizeof(countws));
        for (int i = 0; i < s.size(); i++) {
            countws[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (countws[t[i] - 'a'] > 0) {
                countws[t[i] - 'a']--;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};
