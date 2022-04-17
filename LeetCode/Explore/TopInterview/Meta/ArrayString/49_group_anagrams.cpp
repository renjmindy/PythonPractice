class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string> > mp;
      vector<vector<string> > ans;
      for (auto &str : strs) {
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(str);
      }
      for (auto &m : mp) {
        ans.push_back(m.second);
      }
      return ans;
    }
};
