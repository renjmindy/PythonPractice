class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (auto &stone : stones) {
      pq.push(stone);
    }
    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      //cout << a << " " << b << " " << a - b << endl;
      if (a != b) {
        pq.push(a - b);
      }
    }
    if (pq.size()) {
      return pq.top();
    }
    else {
      return 0;
    }
  }
};
