class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> vps, vpe;
    int ans = 0;
    for (auto &interval : intervals) {
      vps.push_back(interval[0]);
      vpe.push_back(interval[1]);
    }
    sort(vps.begin(), vps.end());
    sort(vpe.begin(), vpe.end());
    for (int i = 0, j = 0; i < vps.size(); i++) {
      if (vps[i] < vpe[j]) {
        ans++;
      }
      else {
        j++;
      }
    }
    return ans;
  }
};
