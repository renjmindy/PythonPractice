class Solution {
public:
    string longestPalindrome(string s) {
        int maxL = 1, ini = 0;
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        for (int r = 0; r < s.size(); r++) {
            for (int l = r; l >= 0; l--) {
                if (r == l) {
                    dp[l][r] = true;
                }
                else if (l + 1 == r) {
                    dp[l][r] = (s.at(l) == s.at(r));
                }
                else {
                    dp[l][r] = (dp[l+1][r-1] && s.at(l) == s.at(r));
                }
                if (dp[l][r] && r - l + 1 > maxL) {
                    maxL = r - l + 1;
                    ini = l;
                }
            }
        }
        return s.substr(ini, maxL);
    }
};
