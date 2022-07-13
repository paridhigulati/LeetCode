class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
  
//         int  m = a.size(), n=a[0].size();
//           vector<vector<int>>dp(m, vector<int>(n,0));
           
         int m = a.size(), n = a[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(a[i][0] == 1) break;
            dp[i][0] = 1;
        }
        
        for(int j=0;j<n;j++)
        {
            if(a[0][j] ==1) break;
            
            dp[0][j]= 1;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(a[i][j] == 1) continue;
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
