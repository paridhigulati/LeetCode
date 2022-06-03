class NumMatrix {
public:
  
    vector<vector<int>>dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n= matrix.size(), m=matrix[0].size();
        if(n==0 || m==0) return;
        
        dp = vector<vector<int>>(n+1, vector<int>(m+1));
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
             dp[i][j] = dp[i-1][j]  + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];   
          
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
         
     
        return dp[r2+1][c2+1] - dp[r2+1][c1]-dp[r1][c2+1]+ dp[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */