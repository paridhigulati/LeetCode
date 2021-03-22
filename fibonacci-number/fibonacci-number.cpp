class Solution {
public:
    /* recursive
    int fib(int n) {
        
        if(n==1||n==0)
            return n;
         int ans;
        ans = fib(n-1) +fib(n-2);
        return ans;
        
    }
}; 
        top down approach or   recursion +  memoizing 
 
    int dp[100];
    
     int fib(int n) {
         if(n==0||n==1)
             return n;
         if(dp[n]!=0)
             return dp[n];
         
         int ans;
         ans=fib(n-1)+fib(n-2);
         return ans;
     }
};


Bottom up or iterative dp 
*/
     int fib(int n) {
         int dp[100]={0};
         dp[1]=1;
         int ans;
         for(int i=2;i<=n;i++)
         {
             
              dp[i]=dp[i-1]+dp[i-2];
         }
         return dp[n];
     }
};
     