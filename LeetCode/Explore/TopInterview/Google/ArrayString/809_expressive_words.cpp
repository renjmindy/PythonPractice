class Solution {
  
private:
  vector<bool> isPresent;
  bool isStretchy(string cur, string s) {
    if (cur.size() > s.size()) {
      return false;
    }
    int i = 0, j = 0;
    while (i < s.size() && j < cur.size()) {
      if (!isPresent[cur[j] - 'a']) {
        return false;
      }
      if (s[i] != cur[j]) {
        return false;
      }
      int chars = 1, curchar = 1;
      while (i < s.size() - 1 && s[i] == s[i + 1]) {
        i++;
        chars++;
      }
      while (j < cur.size() - 1 && cur[j] == cur[j + 1]) {
        j++;
        curchar++;
      }
      int excess = chars - curchar;
      if (curchar > chars) {
        return false;
      }
      else if ((excess == 0) || chars >= 3) {
        i++;
        j++;
      }
      else {
        return false;
      }
    }
    return i == s.size() && j == cur.size();
  }
  
public:
    int expressiveWords(string s, vector<string>& words) {
      isPresent.resize(26, false);
      for (auto &c : s) {
        isPresent[c - 'a'] = true;
      }
      int ans = 0;
      for (auto &cur : words) {
        ans += isStretchy(cur, s);
      }
      return ans;
    }
};
