class Solution {
  
private:
  unordered_map<int, int> mp;
  vector<int> vp;
  
  int dfs(int n) {
    if (n <= 1) {
      return 0;
    }
    else {
      if (!mp.count(n)) {
        mp[n] = min(vp[n - 1] + dfs(n - 1), vp[n - 2] + dfs(n - 2)); 
      }
    }
    return mp[n];
  }
  
public:
  int minCostClimbingStairs(vector<int>& cost) {
    vp = cost;
    return dfs(cost.size());
  }
};
