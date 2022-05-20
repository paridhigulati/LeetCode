class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
       
       // vector<int>dp(m, vector<int>(n));
        vector<vector<int>> dp(m,vector<int>(n,-1));
    
        for(int i=0;i<m;i++)
        {
          
        for(int j=0;j<n;j++)
        {
          if(grid[i][j] == 1) dp[i][j] =0;
            else if(i==0 and j==0)
                dp[i][j] = 1;
            else
            {
                 int up=0, down = 0;
             if(i>0)
                  up = dp[i-1][j];
            if (j>0)  
               down = dp[i][j-1];
            dp[i][j] = up + down;
            }
        }
        }
            return dp[m-1][n-1];
        }
         
};