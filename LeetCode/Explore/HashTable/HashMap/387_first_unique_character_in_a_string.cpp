class Solution {
public:
  int firstUniqChar(string s) {
    int minIdx = INT_MAX;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
      //if (!mp.count(s[i])) {
      //mp[s[i]] = i;
      //}
      //else {
      //mp.erase(s[i]);
      //}
    }
    //if (mp.size() > 0) {
    //for (auto &m : mp) {
    //minIdx = min(minIdx, m.second);
    //}
    //}
    //return minIdx < INT_MAX ? minIdx : -1;
    for (int i = 0; i < s.size(); i++) {
      if (mp[s[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};
