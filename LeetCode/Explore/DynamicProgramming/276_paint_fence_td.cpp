class Solution {
  
private:
  unordered_map<int, int> mp;
  int dfs(int n, int k) {
    if (n == 1) {
      return k;
    }
    if (n == 2) {
      return k * k;
    }
    if (mp.count(n)) {
      return mp[n];
    }
    
    mp[n] = (k - 1) * (dfs(n - 1, k) + dfs(n - 2, k));
    return mp[n];
  }
  
public:
  int numWays(int n, int k) {
    return dfs(n, k);
  }
};
