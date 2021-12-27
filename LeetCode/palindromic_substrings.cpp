class Solution {
public:
    int countSubstrings(string s) {
        int maxL = 1, ini = 0, ans = 0;;
        vector<vector<bool> >  dp(s.size(), vector<bool>(s.size(), false));
        for (int r = 0; r < s.size(); r++) {
            for (int l = r; l >= 0; l--) {
                if (l == r) {
                    dp[l][r] = true;
                    ans += dp[l][r];
                }
                else if (r == l + 1) {
                    dp[l][r] = (s.at(l) == s.at(r));
                    ans += dp[l][r];
                }
                else {
                    dp[l][r] = (dp[l+1][r-1] && (s.at(l) == s.at(r)));
                    ans += dp[l][r];
                }
                if (dp[l][r] && r - l + 1 > maxL) {
                    maxL = r - l + 1;
                    ini = l;
                }
            }
        }
        return ans;
    }
};
