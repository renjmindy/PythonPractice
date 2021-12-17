//bool comp (pair<int, int> &a, pair<int, int> &b) {
//    return a.second > b.second;
//}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int idx = prices.size() - 1;
        //int minIdx = min_element(prices.begin(), prices.end()) - prices.begin();
        //int minVal = *min_element(prices.begin(), prices.end());
        int minVal = prices[0];
        int maxVal = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices.at(i) < minVal) {
                minVal = prices.at(i);
            }
            else {
                maxVal = max(maxVal, prices.at(i) - minVal);
            }
        }
        
        return maxVal;
        
        /*map<int, int> m;
        vector<pair<int, int> > v;
        
        if (minIdx == idx) {
            return 0;
        } 
        
        while (idx > minIdx) {
            if (prices.at(idx) - prices.at(minIdx) > 0) {
                m[idx - minIdx] = prices.at(idx) - prices.at(minIdx);
            }
            idx -= 1;
        }
        
        if (!m.empty()) {
            for (auto &i : m) {
                v.push_back(i);
            }
            sort(v.begin(), v.end(), comp);
        }
        
        return (v.size() > 0) ? v[0].second : 0;*/
        
    }
};

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        #maxiDiff = 0
        
        #for i in range(0, len(prices)-1, 1):
        #    iniPrice = prices[i]
        #    for j in range(i+1, len(prices), 1):
        #        finPrice = prices[j]
        #        if finPrice - iniPrice > maxiDiff:
        #            maxiDiff = finPrice - iniPrice
                    
        #return maxiDiff
        
        if len(prices) < 2:
            return 0
        
        maxiDiff = -0.0001
        minStock = prices[0]
        
        for p in prices:
            
            maxiDiff = max(maxiDiff, p - minStock)
            minStock = min(minStock, p)
            
        return maxiDiff
            
        
