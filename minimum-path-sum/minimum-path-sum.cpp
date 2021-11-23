class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     
        //storage and meaning -> ith cell se destination ka min path 
        // destination se destinatio is smaller hence direction = bottom to top 
        
        
        
    int row=grid.size();
    int col=grid[0].size();
    int dp[row][col];
        
    for(int i=row-1;i>=0;i--){
    for(int j=col-1 ; j>=0 ; j--){
        
            if(i==row-1 and j==col-1){ //means we are at end cell
                dp[i][j]=grid[i][j];
            }
            else if(i==row-1){  //means we are at last row
            
                dp[i][j]=grid[i][j]+dp[i][j+1];// we can go only right 
            }
            else if(j==col-1){ //means we are at last col
            
                dp[i][j]=grid[i][j]+dp[i+1][j];// we can have only down
            }
            else{  //rest of the cell
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);// get the min of right and down cell;
                
            } 
    }
    }
        return dp[0][0];
    }
};
        