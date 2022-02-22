class Solution {
  
private:
  unordered_map<int, int> mp;
  vector<int> vp;
  
  int dfs(int n) {
    if (n == 0) {
      return vp[0];
    }
    else if (n == 1) {
      return max(vp[0], vp[1]);
    }
    else {
      if (!mp.count(n)) {
        mp[n] = max(dfs(n - 1), dfs(n - 2) + vp[n]);
      }
    }
    return mp[n];
  }
  
public:
  int rob(vector<int>& nums) {
    vp = nums;
    return dfs(vp.size() - 1);
  }
};
