class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      typedef pair<int, int> P;
      priority_queue<P, vector<P>, greater<P> > pq; // ascending
      vector<vector<int> > ans;
      for (int i = 0; i < points.size(); i++) {
        pq.push(make_pair(pow(points[i][0], 2) + pow(points[i][1], 2), i));
      }
      while (k) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
        k--;
      }
      return ans;
    }
};
