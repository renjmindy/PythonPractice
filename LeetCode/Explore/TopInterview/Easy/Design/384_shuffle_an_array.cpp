class Solution {
  
private:
  vector<int> v, t;
  
public:
  Solution(vector<int>& nums) {
    v = nums;
    t = nums;
  }
  
  vector<int> reset() {
    t = v;
    return t;
  }
  
  vector<int> shuffle() {
    vector<bool> visited(v.size(), false);
    for (int i = 0; i < v.size(); i++) {
      int p = rand() % v.size();
      while (visited[p]) {
        p = rand() % v.size();
      }
      t[i] = v[p];
      visited[p] = true;
    }
    return t;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
