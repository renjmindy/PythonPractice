class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      //int i = *max_element(nums.begin(), nums.end());
      int i = nums.size();
      sort(nums.begin(), nums.end());
      vector<int> ans;
      for (int j = 1; j <= i; j++) {
        vector<int>::iterator itr = find(nums.begin(), nums.end(), j);
        if (itr == nums.end()) {
          ans.push_back(j);
        }
      } 
      return ans;
    }
};
