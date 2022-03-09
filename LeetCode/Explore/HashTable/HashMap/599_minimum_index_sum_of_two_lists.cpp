class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<int, vector<string> > mp;
    int minIdx = INT_MAX;
    for (int i = 0; i < list1.size(); i++) {
      for (int j = 0; j < list2.size(); j++) {
        if (list1[i] == list2[j]) {
          mp[i + j].push_back(list1[i]);
        }
      }
    }
    for (auto &m : mp) {
      minIdx = min(minIdx, m.first);
    }
    return {mp[minIdx]};
  }
};
