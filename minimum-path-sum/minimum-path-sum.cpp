class Solution {
public:
    
    //recursive --------> tc = exponential 
   /* 
    int minPathSum(vector<vector<int>>& grid) {
        
        if(grid.size()==0)
            return 0;
    
        int ans = rec(0,0,grid);
        return ans;
    }
        int rec(int i, int j, vector<vector<int>>& grid)
        {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        if(i==row && j==col)
            return grid[i][j];
        if(i>row || j>col)
        return INT_MAX;
        int op1 = rec(i,j+1,grid);
        int op2 = rec(i+1,j,grid);
       return grid[i][j]+ min(op1,op2);
        
        
    } 
};

   
   // dp 
      int minPathSum(vector<vector<int>>& grid) {
           if(grid.size()==0)
            return 0;
     int col = grid[0].size()-1;
          //dp table
          vector<vector<int>>dp(grid.size(), vector<int>(col,0));
          dp[0][0]=grid[0][0]; //1st element as starting point
          // to fill the rows
          for(int i=1;i<col;i++)
          {
              dp[0][i]= dp[0][i-1] + grid[0][i];
          }
          //to fill 1st col because only 1st row and 1st col has 1 option rest all have 2 options 
          for(int i=1;i<grid.size();i++)
          {
              dp[i][0]= dp[i-1][0]+ grid[i][0];
          }
          //to fill the rest of cells 
          for(int i=1;i<grid.size();i++)
          {
              for(int j=1;j<col;j++)
              {
                  dp[i][j]= grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
              }
          }
              return dp[grid.size()-1][col-1];
          }
};
*/

    int minPathSum(vector<vector<int>>& grid) {
        //Fast I/O in C++
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int rows = grid.size();
        if(rows==0)
            return 0;
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int i,j;
        
        dp[0][0] = grid[0][0];  //1st element is starting point
        //Fill 1st row
        for(i=1;i<cols;++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        //Fill 1st Col
        for(i=1;i<rows;++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
        //Now fill the rest of the cell
        for(i=1;i<rows;++i)
        {
            for(j=1;j<cols;++j)
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
        return dp[rows-1][cols-1];
    }
};