class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        reverse(s.begin(), s.end());
        string sp;
        while (r < s.size()) {
            while (l < s.size() && !isblank(s[l])) {
                l++;
            }
            if (l > r) {
                reverse(s.begin() + r, s.begin() + l);
                for (int i = r; i < l; i++) {
                    sp += s[i];
                }
                sp += ' ';
            }
            l++;
            r = l;
        }
        sp.erase(remove(sp.end() - 1, sp.end(), ' '), sp.end());
        return sp;
    }
};
