class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int mid = l + (r - l) / 2;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums.at(i) == nums.at(mid)) {
                count += 1;
            }
        }
        return (count > (int)(nums.size() / 2)) ? nums.at(mid) : -1;
    }
};

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        nList = list(set(nums))
        nDict = {k:0 for k in nList}
        
        for n in nums:
            nDict[n] = nDict.get(n, 0) + 1
            
        kMax = -1
        vMax = -1
        
        for k in nDict.keys():
            if nDict[k] > vMax:
                kMax = k
                vMax = nDict[k]
        
        
        return kMax
