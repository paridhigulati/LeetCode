class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
  
        int  m = a.size(), n=a[0].size();
          vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0,0,a, dp);
        
    }
    
        int solve(int i , int j, vector<vector<int>>& a , vector<vector<int>> & dp)
        {
              int  m = a.size(), n=a[0].size();
          
            
        
        if(i==m-1 and j== n-1 and !a[i][j]) return  1;
        
        if(j>=n || j < 0 || i< 0|| i>=m) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
        
            if(a[i][j]) return 0;
            
        
       return   dp[i][j] =  solve(i+1, j, a,dp) + solve(i, j+1, a,dp);
        
    }
};
    
    
   