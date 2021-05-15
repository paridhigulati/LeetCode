/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minSoFar = INT_MAX;
        int overallP = 0;
        int ProfitToday =0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i] < minSoFar)
               minSoFar = prices[i];
            ProfitToday = prices[i] - minSoFar;
            if(overallP < ProfitToday)
                overallP = ProfitToday;
            
        }
        return overallP;
        
    }
};
*/
    class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0], profit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] > buy) profit = max(prices[i]-buy, profit);
            else                 buy    = prices[i];
        }
        return profit;
    }
};