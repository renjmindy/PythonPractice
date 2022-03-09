class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string> > mp;
    vector<vector<string> > ans;
    for (auto &str : strings) {
      string s = ":";
      for (int i = 1; i < str.size(); i++) {
        int diff = (str[i] - str[0] + 26) % 26;
        s += to_string(diff);
        s += ":";
      }
      //cout << s << endl;
      mp[s].push_back(str);
    }
    for (auto &m : mp) {
      ans.push_back(m.second);
    }
    return ans;
  }
};
