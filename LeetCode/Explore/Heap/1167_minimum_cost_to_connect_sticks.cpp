class Solution {
public:
  int connectSticks(vector<int>& sticks) {
    // min-heap employeed to minimize cost
    priority_queue<int, vector<int>, greater<int> > pq(sticks.begin(), sticks.end());
    int ans = 0;
    while (pq.size()) {
      int a = pq.top();
      pq.pop();
      if (pq.size()) {
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
      }
    }
    return ans;
  }
};
