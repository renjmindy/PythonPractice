class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;
        vector<vector<string> > ma;
        for (auto s : strs) {
            string sc = s;
            sort(s.begin(), s.end());
            mp[s].push_back(sc);
        }
        for (auto p : mp) {
            ma.push_back(p.second);
        }
        return ma;
    }
}; 
