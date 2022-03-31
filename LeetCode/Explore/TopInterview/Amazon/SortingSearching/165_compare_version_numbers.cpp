class Solution {
  
private:
  vector<string> tokenize(string s, string del = " ") {
    int i = 0, j = s.find(del);
    vector<string> ans;
    while (j != -1) {
      ans.push_back(s.substr(i, j - i));
      i = j + del.size();
      j = s.find(del, i);
    }
    ans.push_back(s.substr(i, j - i));
    return ans;
  }
  
public:
    int compareVersion(string version1, string version2) {
      vector<string> nums1 = tokenize(version1, ".");
      vector<string> nums2 = tokenize(version2, ".");
            
      for (int i = 0; i < max(nums1.size(), nums2.size()); i++) {
        int v1 = i < nums1.size() ? stoi(nums1[i]) : 0;
        int v2 = i < nums2.size() ? stoi(nums2[i]) : 0;
        if (v1 != v2) {
          return v1 > v2 ? 1 : -1;
        }
      }
      return 0;
    }
};
