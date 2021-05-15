class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        // WHY THIS DOESNT WORK 
        /*int res=INT_MIN;
        int total=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                total = prices[i+1]-prices[i];
                res = max(res,total);
               
            }
        }
        return res+fee;
    }
};  */
         int obsp = -prices[0]; // pehla share ka loan 
            int ossp = 0;
        for(int i=1;i<prices.size();i++)
        {
           int nbsp = 0;
            int nssp =0;
            if(ossp-prices[i] > obsp)
                nbsp = ossp-prices[i];
            else
                nbsp = obsp;
            if(ossp  < (prices[i] + obsp)-fee )
               nssp = prices[i]+obsp -fee;
               else
               nssp = ossp;
            obsp = nbsp;
               ossp=nssp;
            
        }
               return ossp;
               }
               };