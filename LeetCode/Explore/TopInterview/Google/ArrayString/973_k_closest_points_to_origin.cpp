class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int> > ans;
      typedef pair<int, int> P;
      priority_queue<P, vector<P>, greater<P>> pq;
      int i = 0;
      for (auto &point : points) {
        pq.push(make_pair(pow(point[0], 2) + pow(point[1], 2), i));
        i++;
      }
      while (k) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
        k--;
      }
      return ans;
    }
};
