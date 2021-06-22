class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        vector<int>dp(n);
        dp[0]=1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(2*dp[t2],min(3*dp[t3],5*dp[t5]));
            if(dp[i]==2*(dp[t2]))
                t2++;
            if(dp[i]==3*dp[t3])
                t3++;
            if(dp[i]==5*dp[t5])
                t5++;
        }
        return dp[n-1];
        
    }
};