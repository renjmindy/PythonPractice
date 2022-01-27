class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> wc(128);
        string ans;
        int len = 0;
        for (auto& c: t) {
            wc[c]++;
        }
        
        for (int l = 0, r = 0; r < s.size() && l < s.size(); r++) {
            if (wc[s[r]] > 0) {
                len++;                
            }
            wc[s[r]]--;
        
            if (len < t.size()) {
                continue;
            }
            else {
                while (l < s.size() && wc[s[l]] < 0) {
                    wc[s[l]]++;
                    l++;
                }
            
                if (ans.empty() || (r - l + 1) < ans.size()) {
                    ans = s.substr(l, r - l + 1);
                }
            }
        }
        return ans;
    }
};
