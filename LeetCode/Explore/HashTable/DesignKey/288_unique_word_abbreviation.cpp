class ValidWordAbbr {
  
private:
  unordered_map<string, unordered_set<string> > mp;
  string makeAbbr(string s) {
    if (s.size() <= 2) {
      return s;
    }
    else {
      return s[0]+to_string(s.size() - 2)+s.back();
    }
  }
  
public:
  ValidWordAbbr(vector<string>& dictionary) {
    for (auto &word : dictionary) {
      mp[makeAbbr(word)].insert(word);
    }
  }
  
  bool isUnique(string word) {
    string abbr = makeAbbr(word);
    if (!mp.count(abbr)) {
      return true;
    }
    return mp[abbr].size() == 1 && (*mp[abbr].begin() == word);
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
