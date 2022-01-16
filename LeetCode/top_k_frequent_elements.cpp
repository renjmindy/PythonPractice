class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size()) {
            return nums;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums.at(i)]++; 
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>ans;
        
        for(auto i : mp){
            if(pq.size() < k){
                pq.push({i.second, i.first});
            }
            else if (pq.size() == k && i.second > pq.top().first){
                pq.pop();
                pq.push({i.second,i.first});
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
