class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int hottest = 0;
      vector<int> ans(temperatures.size(), 0);
      for (int i = temperatures.size() - 1; i >= 0; i--) {
        if (temperatures[i] >= hottest) {
          hottest = temperatures[i];
          continue;
        }
        int days = 1;
        while (temperatures[i + days] <= temperatures[i]) {
          days += ans[i + days];
        }
        ans[i] = days;
      }
      return ans;
    }
};
