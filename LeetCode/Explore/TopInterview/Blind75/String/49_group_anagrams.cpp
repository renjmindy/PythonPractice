// one pass hash table
// Complexity Analysis
// Time Complexity: O(NK \log K)O(NKlogK), where NN is the length of strs, and KK is the maximum length of a string in strs. 
// The outer loop has complexity O(N)O(N) as we iterate through each string. Then, we sort each string in O(K \log K)O(KlogK) time.
// Space Complexity: O(NK)O(NK), the total information content stored in ans.

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > mp;
    vector<vector<string> > vp;
    for (auto &str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      mp[tmp].push_back(str);
    }
    for (auto &m : mp) {
      vp.push_back(m.second);
    }
    return vp;
  }
};
