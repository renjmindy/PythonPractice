class Solution {

private:
  unordered_map<int, int> mp;
  
  int dfs(int n) {
    if (n <= 2) {
      return n;
    }
    else {
      if (!mp.count(n)) {
        mp[n] = dfs(n - 1) + dfs(n - 2);
      }
    }
    return mp[n];
  }
  
public:
  int climbStairs(int n) {
    return dfs(n);
  }
};
