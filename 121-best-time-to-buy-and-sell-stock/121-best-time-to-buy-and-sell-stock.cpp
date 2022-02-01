class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //to buy, it should be minsofar and sell on maxsofar
        

        
        
        int minSoFar =INT_MAX;
        int maxSoFar = INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
            
            minSoFar = min(prices[i], minSoFar);
            maxSoFar = max(prices[i] - minSoFar, maxSoFar);
        }
        return (maxSoFar);
        
    }
};

















































