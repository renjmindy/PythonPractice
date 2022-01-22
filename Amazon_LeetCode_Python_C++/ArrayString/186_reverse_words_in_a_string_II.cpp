class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int r = 0, l = 0;
        while (r < s.size()) {
            while (l < s.size() && !isblank(s[l])) {
                l++;
            }
            reverse(s.begin() + r, s.begin() + l);
            l++;
            r = l;
        }
    }
};
