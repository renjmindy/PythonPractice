class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    int found = haystack.find(needle);
    return found;
    /*for (int i = 0; i < haystack.size(); i++) {
      if (haystack[i] == needle[0]) {
        if (haystack.substr(i, needle.size()) == needle) {
          return i;
        }
      }
    }
    return -1;*/
  }
};
