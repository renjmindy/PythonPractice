class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> mp;
      priority_queue<pair<int, int> > pq;
      vector<int> ans;
      for (auto &num : nums) {
        mp[num]++;
      }
      for (auto &m : mp) {
        pq.push(make_pair(m.second, m.first));
      }
      while (k) {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
      }
      return ans;
    }
};
