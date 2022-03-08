class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> sp;
    for (int i = 0; i < nums.size(); i++) {
      if (!sp.count(nums[i])) {
        sp.insert(nums[i]);
      }
      else {
        sp.erase(nums[i]);
      }
    }
    for (auto it = sp.begin(); it != sp.end(); ++it) {
      //cout << (*it) << " ";
      ans = (*it);
    }
    return ans;
  }
};
