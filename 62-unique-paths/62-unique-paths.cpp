class Solution {
public:
    int uniquePaths(int m, int n) {
        
        
       int i=m-1, j=n-1;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(i,j,m,n, dp);
    }
    
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        
        if(i <  0 || j < 0 )
        {
            return 0;
        }
        if(i==0 and j==0) return 1;
        
        if(dp[i][j] != -1)
         return dp[i][j];
        
        dp[i][j] = solve(i-1,j,m,n,dp) + solve(i, j-1,m,n,dp);
        
        return dp[i][j];
        
            }
};
 