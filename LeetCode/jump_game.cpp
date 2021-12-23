class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_stop = 0, jump_dist = 0;
        while (curr_stop < nums.size() && curr_stop <= jump_dist) {
            jump_dist = max(jump_dist, curr_stop + nums.at(curr_stop));
            curr_stop += 1;
        }
        return curr_stop == nums.size();
    }
};
