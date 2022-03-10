class Solution {
  
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    typedef pair<int, int> P;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> ans;
    for(int i = 0; i < mat.size(); i++) {
      int sum = 0;
      for(int j = 0; j < mat[0].size(); j++) {
        sum += mat[i][j];
      }
      pq.push(make_pair(sum, i));
    }
    
    for(int i = 0; i < k; i++) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    return ans;
  }
};
