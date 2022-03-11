// min-heap priority queue used. Based on the logic that we have to use stairs for largest climp and bricks for small leaps. 
// we iterate loop till we have bricks left and maintain min-heap in which we will store the highest climb. we do so by having 
// a if-case which maintains the size of priority queue equal to ladders.

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < heights.size() - 1; i++) {
      if (heights[i + 1] - heights[i] <= 0) {
        continue;
      }
      else {
        pq.push(heights[i + 1] - heights[i]);
        if (pq.size() <= ladders) {
          continue;
        }
        else {
          bricks -= pq.top();
          pq.pop();
          if (bricks < 0) {
            return i;
          }
        }
      }
    }
    return heights.size() - 1;
  }
};
