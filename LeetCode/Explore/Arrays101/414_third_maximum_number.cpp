class Solution {
public:
    int thirdMax(vector<int>& nums) {
      sort(nums.begin(), nums.end(), greater<int>());
      set<int> sp;
      for (auto &num : nums) {
        sp.insert(num);
      }
      set<int>::iterator itr = sp.end();
      if (sp.size() >= 3) {
        for (int i = 0; i < 3; i++) {
          itr--;
        }
      }
      else {
        itr--;
      }
      return *itr;
    }
};
