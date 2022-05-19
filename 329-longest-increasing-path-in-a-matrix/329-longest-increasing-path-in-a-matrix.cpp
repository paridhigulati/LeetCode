class Solution {
public:
    
    vector<vector<int>>dp ;
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       
        int m = matrix.size();
        int n = matrix[0].size();
        
        dp.resize(m, vector<int>(n));
        
        int ans =  1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans = max(ans, dfs(i,j,matrix));
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, vector<vector<int>>& matrix)
    {
        
        if(dp[i][j]) return dp[i][j];
        
        dp[i][j]=1;
        
        vector<vector<int>>dir = { { 0,1} , {0,-1}, {-1,0}, {1,0}};
          int m = matrix.size();
        int n = matrix[0].size();
        
     
        for(auto it : dir)
        {
            int nrow = i + it[0];
            int ncol = j + it[1];
            
            if(nrow >= m or ncol >= n or nrow < 0 or ncol <0 or matrix[i][j] >= matrix[nrow][ncol]) continue;
            
            dp[i][j] = max(dp[i][j], 1+ dfs(nrow,ncol,matrix));
        }
        return dp[i][j];
    }
};

