class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        /*int bd=0; //buying date
        int sd=0; // selling date
        int profit =0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]>=prices[i-1]) //increase horha upstroke h so selling date ko aage move
                sd++;
            else 
              profit +=  prices[sd]-prices[bd];//decrease h so purana profit collect krlo 
               bd=sd=i;
        }
           profit +=  prices[sd]-prices[bd];
        return profit;
    }
};
*/
        
        int length = prices.size();
        int total =0;
        if(length == 1)
        {
            return 0;
        }
        for(int i =0; i < length -1 ; i++)
        {
            if(prices[i] < prices[i+1])
            {
                total += prices[i+1] - prices[i];
                
            }
        }
        return total;
        
    }
};