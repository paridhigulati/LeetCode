class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //to buy, it should be minsofar and sell on maxsofar
     int minSofar =INT_MAX;
        int maxSofar = INT_MIN;
        int ans=0;
    for(int i=0;i<prices.size();i++)
    {
        minSofar = min(minSofar,prices[i]);
          maxSofar = max(maxSofar, prices[i]-minSofar);
    }
        ans = max(ans, maxSofar);
     return ans;
    }
};

















































