class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    typedef pair<int, pair<int, int> > P;
    priority_queue<P, vector<P>, greater<P>> pq;
    
    int val;
    for (int col = 0; col < matrix[0].size(); col++) {
      pq.push(make_pair(matrix[0][col], make_pair(0, col)));
    }
    for (int i = 0; i < k; i++) {
      val = pq.top().first; 
      int a = pq.top().second.first;
      int b = pq.top().second.second;
      //cout << a << " " << b << " " << val << endl;
      pq.pop();
      if (a < matrix.size() - 1) {
        pq.push(make_pair(matrix[a + 1][b], make_pair(a + 1, b)));
      }
    }
    return val;
  }
};
