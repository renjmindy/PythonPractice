class Solution {
public:
    int heightChecker(vector<int>& heights) {
      int ans = 0;
      vector<int> heights_sort = heights;
      sort(heights_sort.begin(), heights_sort.end());
      for (int i = 0; i < heights_sort.size(); i++) {
        if (heights_sort.at(i) != heights.at(i)) {
          ans += 1;
        }
      }
      return ans;
    }
};
