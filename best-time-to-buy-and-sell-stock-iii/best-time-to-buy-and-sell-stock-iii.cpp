class Solution {
public: /*
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        // left to right -> profit if sold today or till today 
        int mpist = 0;
        int lsf = prices[0];
        int mpisut[prices.size()];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<lsf)
                lsf = prices[i];
            mpist = prices[i]-lsf;
            if(mpist > mpisut[i-1])
            {
                 mpisut[i] = mpist; 
            }
            else
                mpisut[i] = mpisut[i-1];
        }
        // now right to left
        int mpibt =0;
        int mxat = prices[n-1]; // max after today
        int mpibat[n];
        for(int i=n-2;i>=0;i--)
        {
        if(prices[i]>mxat)
        {
            mxat = prices[i];
        }
            mpibt = mxat - prices[i];
            if(mpibt > mpibat[i+1])
            {
                mpibat[i] = mpibt;
            }
            else 
                mpibat[i] = mpibat[i+1];
        }
        int op;
        for(int i=0;i<n;i++)
        {
            if(mpibat[i]+mpisut[i] > op)
            {
                op = mpibat[i]+mpisut[i];
            }
        }
            return op;
    }
}; */
   
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int leastSoFar=prices[0];
        int maxProfitTillNow=0;
        
        vector<int> dpleft(size);
        
        for(int i=1;i<size;i++){
            if(prices[i]<leastSoFar){
                leastSoFar=prices[i];
            }
            maxProfitTillNow=prices[i]-leastSoFar;
            if(dpleft[i-1]<maxProfitTillNow){
                dpleft[i]=maxProfitTillNow;
            }
            else{
                dpleft[i]=dpleft[i-1];
            }
        }
        
        int maxProfitIfBoughtToday=0;
        int maxAfterToday=prices[size-1];
        vector<int> dpright(size);
        
        for(int i=size-2 ;i>=0;i--){
            if(prices[i]>maxAfterToday){
                maxAfterToday=prices[i];
            }
            maxProfitIfBoughtToday=maxAfterToday-prices[i];
            if(dpright[i+1]<maxProfitIfBoughtToday){
               dpright[i]=maxProfitIfBoughtToday; 
            }
            else{
                 dpright[i]=dpright[i+1];
            }
        }
        
        int maxProfit=0;
        
        for(int i=0;i<size;i++){
            if(dpleft[i]+dpright[i]>maxProfit){
                maxProfit=dpleft[i]+dpright[i];
            }
        }
        return maxProfit;
    }
};