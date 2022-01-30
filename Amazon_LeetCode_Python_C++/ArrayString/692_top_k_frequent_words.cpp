class Solution {
    
public:
    static bool comp(pair<int, string> &a, pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        else {
            return a.first > b.first;
        }
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<int, string> > vp;
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }
        for (auto &m : mp) {
            vp.push_back(make_pair(m.second, m.first));
        }
        sort(vp.begin(), vp.end(), comp);
        for (int i = 0; i < k; i++) {
            ans.push_back(vp[i].second);
        }
        return ans;
    }
};
