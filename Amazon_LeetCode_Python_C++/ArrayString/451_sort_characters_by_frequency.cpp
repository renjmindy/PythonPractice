class Solution {    
public:
    string frequencySort(string s) {
        //int count[26];
        //memset(count, 0, sizeof(count));
        unordered_map<char, int> mp;
        vector<pair<char, int> > vp;
        string t;
        for (int i = 0; i < s.size(); i++) {
            //count[s[i] - 'a']++;
            mp[s[i]]++;
        }
        for (auto &m : mp) {
            vp.push_back(make_pair(m.first, m.second));
        }
        sort(vp.begin(), vp.end(), [] (const auto &a, const auto &b) { return a.second > b.second; });
        for (int i = 0; i < vp.size(); i++) {
            for (int j = 0; j < vp[i].second; j++) {
                t += vp[i].first;
            }
        }
        return t;
    }
};
