class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums.at(i)] += 1;
            if (m[nums.at(i)] > 1) {
                return true;
            }
        }
        
        return false;
    }
};

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        sList = list(set(nums))
        
        if len(nums) > len(sList):
            return True
        else:
            return False
