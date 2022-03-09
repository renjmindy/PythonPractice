class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<pair<int, int> > vp;
    vector<int> ans;
    for (auto &num : nums) {
      mp[num]++;
    }
    for (auto &m : mp) {
      vp.push_back(make_pair(m.second, m.first));
    }
    sort(vp.begin(), vp.end(), greater<pair<int, int> >());
    for (int i = 0; i < k; i++) {
      ans.push_back(vp[i].second);
    }
    return ans;
  }
};
