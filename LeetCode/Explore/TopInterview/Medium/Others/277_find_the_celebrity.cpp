/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
  
private:
  int numOfPeople;
  bool isCelebrity(int i) {
    for (int j = 0; j < numOfPeople; j++) {
      if (i == j) {
        continue;
      }
      if (knows(i, j) || !knows(j, i)) {
        return false;
      }
    }
    return true;
  }
  
public:
    int findCelebrity(int n) {
      numOfPeople = n;
      int candidateCelebrity = 0;
      for (int i = 1; i < n; i++) {
        if (knows(candidateCelebrity, i)) {
          candidateCelebrity = i;
        }
      }
      return isCelebrity(candidateCelebrity) ? candidateCelebrity : -1;
    }
};
