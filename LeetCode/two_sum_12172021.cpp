class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums.at(i)) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[target - nums.at(i)]);
            }
            m[nums.at(i)] = i;
        }
        return ans;
    }
};

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        tList = []
        
        for n in range(0, len(nums), 1):
            for m in range(n+1, len(nums), 1):
                if nums[n] + nums[m] == target:
                    tList.append(n)
                    tList.append(m)
                else:
                    continue
                    
        return tList
