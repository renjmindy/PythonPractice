/* Suppose a is the character with count as maxSameCharCount.
   Current substring window size is given by curWindowSize = windowEnd - windowStart + 1.
   In the current window, maxSameCharCount characters are same (which is 'a'). If we can 
   replace curWindowSize - maxSameCharCount characters with 'a', then our current window
   will have all characters same (which is 'a'). However we can only replace k characters.
   So if curWindowSize - maxSameCharCount > k, then current window is invalid. So we
   move windowStart forward to find a suitable window. Decrease character count of
   character pointed by windowStart when window is changed
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        //unordered_map<char, int> mp;
        unordered_map<char, int> mc;
        int ans = 0;
        int count = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            mc[s[r]]++;
            count = max(count, mc[s[r]]);
            if (r - l + 1 - count > k) {
                mc[s[l]]--;
                l++;
            }
            //if (mp.find(s[r]) != mp.end()) {
            //    l = max(l, mp[s[r]]);
            //}
            ans = max(ans, r - l + 1);
            //mp[s[r]] = r + 1;
        }
        return ans;
    }
};
