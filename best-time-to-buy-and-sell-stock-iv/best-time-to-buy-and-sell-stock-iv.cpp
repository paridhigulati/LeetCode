class Solution {
public:  
    // O(n^2)
    int maxProfit(int k, vector<int>& prices) {
        int size=prices.size();
        if(size==0){
            return size;
        }
        vector<vector<int>> dp(k+1,vector<int>(size));
        
        for(int tr=1;tr<=k;tr++){
            int max=INT_MIN;
            for(int day=1;day<size;day++){
                if(dp[tr-1][day-1]-prices[day-1] >max){
                    max=dp[tr-1][day-1]-prices[day-1];
                }
                if(max+prices[day] > dp[tr][day-1]){
                    dp[tr][day]=max+prices[day];
                }
                else{
                    dp[tr][day]=dp[tr][day-1];
                }
            }
        }
        return dp[k][size-1];
    }
};