class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    typedef pair<int, int> P;
    priority_queue<P, vector<P>> pq;
    vector<vector<int> > ans;
    int i = 0;
    for (auto &point : points) {
      pq.push(make_pair(pow(point[0], 2) + pow(point[1], 2), i));
      i++;
      // if the heap size is greater than k, remove the smallest element
      if (pq.size() > k) {
        pq.pop();
      }
    }
    while (pq.size() > 0) {
      ans.push_back(points[pq.top().second]);
      pq.pop();
    }
    return ans;
  }
};
