/*example: [ball, able, area, lead, lady]
we will create a hash table of prefixes to a list of words having that prefixes:
so we'll have a hash map as follows:

key: value
"b": ["ball"]
"ba":["ball"]
"ball":["ball"]
"ball":["ball"]
"a": ["able", "area"]
"ar":["area"]
"are":["area"]
"area":["area"]
........

Then we simply loop through the words list and pick a word and try to see if we can form a word square.
in the backtracking() function we'll send the integer index, which means the new word we pick, should start with(have a prefix of) character located at this index in the previous words we picked.

when index == word length we are done and we have successfully found a vector of strings that form a word square and we add it in the final result. and continue trying to see if we can start with other words and repeat the process.

backtracking+hash Map*/

class Solution {
  
private:
  unordered_map<string, vector<string> > prefixMap;
  vector<vector<string> > ans;
  vector<string> tmp;
  void buildMap(vector<string> &words, unordered_map<string, vector<string> > &prefixMap) {
    for (auto &word : words) {
      for (int i = 1; i < word.size(); i++) {
        string pre = word.substr(0, i);
        prefixMap[pre].push_back(word);
      }
    }
  }
  
  void backtrack(int idx, int n, vector<string> &tmp, vector<vector<string> > &ans, unordered_map<string, vector<string> > &prefixMap) {
    if (idx == n) {
      ans.push_back(tmp);
      return;
    }
    string prefix = "";
    for (auto &word : tmp) {
      prefix += word[idx];
    }
    vector<string> candidate = prefixMap[prefix];
    for (auto &s : candidate) {
      tmp.push_back(s);
      backtrack(idx + 1, n, tmp, ans, prefixMap);
      tmp.pop_back();
    }
  }
  
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
      buildMap(words, prefixMap);
      for (auto &word : words) {
        tmp.push_back(word);
        backtrack(1, words[0].size(), tmp, ans, prefixMap);
        tmp.pop_back();
      }
      return ans;
    }
};
