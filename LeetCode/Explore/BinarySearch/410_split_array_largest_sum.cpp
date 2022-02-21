class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    // Idea is to find a value between max num in array and total array sum which satisfy condition totalsplit <= m
    
    // Find max element in array and total sum
    int left = 0, right = 0;
    for(auto num: nums) {
      left = max(left, num);
      right += num;
    }
    
    // Edge case
    if(m == 1) {
        return right;
    }
    
    int ans = 0;
    while(left < right) {
      int mid = left + (right-left)/2;
      
      // Find how many split we need for mid as a max possible sum of sub arrays
      int split = 1;
      int sum = 0;
      for(auto num: nums) {
        if(sum + num <= mid) {
          sum += num;
        }
        else {
          split++;
          sum = num;
        }
      }
      
     // if split is less them m it means mid (splited array sum) is more and we want to reduce it
      if(split <= m) {
        right = mid;
        ans = mid;
      }
      else {
        left = mid+1;
      }
    }
    return ans;
  }
};
