class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n+1);
        dp[0]=1;
       
        vector<int>pointer(primes.size(),0);
        for(int i=1;i<n;i++)
        {
            dp[i] = INT_MAX;
            for(int j=0;j<primes.size();j++)
            {
                dp[i] = min(dp[i],(primes[j]*dp[pointer[j]]));
               
            }
            
             for(int j=0;j<primes.size();j++)
             {
                if(primes[j]*dp[pointer[j]]==dp[i])
                pointer[j]++;
             }
            }
        
        return dp[n-1];
                
        }
    
};

