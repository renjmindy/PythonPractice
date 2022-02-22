class Solution {
  
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<long long,long long>> v(nums.size()); //vector to store values and indexes
    for(int i = 0 ; i < nums.size(); i++) {
      v[i].first = nums[i]; //store values to compare with t
      v[i].second = i; //store indexes to compare with k
    }
    sort(v.begin(), v.end());
    
    for(int i = 0 ; i  < nums.size() ; i++) {
      for(int j = i + 1 ; j < nums.size() && abs(v[i].first - v[j].first) <= t ; j++) {
        if(abs(v[i].first - v[j].first) <= t) {
          if(abs(v[i].second - v[j].second) <= k) {
            return true;
          }
        }
      } 
    }
    return false;
  }
};
