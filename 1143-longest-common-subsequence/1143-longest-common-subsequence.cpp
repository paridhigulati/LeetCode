class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
     //brute- O(2^n * 2^m)
     // 1 + f(n-1,m-1)    or   max(f(n-1,m) , f(n,m-1))
        
        
      // optimal O(n*m)
        int n = t1.size(), m= t2.size();
        
        //base case when i<0 or j<0 but we cant right dp[-1] so shift index 
        vector<vector<int>>dp(n+1, vector<int>(m+1,0)); 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                if(t1[i-1] == t2[j-1])
        
                //if match
              dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    //not match, take max of either 
                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
        }
                    
                    return dp[n][m];
    } 
};
       
       
       