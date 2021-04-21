class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minP = 1e9;
        for(int i=0;i<prices.size();i++)
        {
            minP = min(minP , prices[i]);
            maxP = max(maxP, prices[i]-minP);
        }
        return maxP;
        
    }
};