class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        int maxGold = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> boolGrid(m, vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] > 0){
                    int gold = helper(grid,i,j,m,n,boolGrid);
                    maxGold = max(maxGold,gold);
                }
            }
        }
        return maxGold;
    }
    
    int helper(vector<vector<int>> &grid, int i,int j, int m, int n, vector<vector<bool>> &boolGrid){
        
        
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0 || boolGrid[i][j]) return 0;
        
        boolGrid[i][j] = true;
        int left = helper(grid,i,j-1,m,n,boolGrid);
        int right = helper(grid,i,j+1,m,n,boolGrid);
        int up = helper(grid,i-1,j,m,n,boolGrid);
        int down = helper(grid,i+1,j,m,n,boolGrid);
        boolGrid[i][j] = false;
        
        return max(left, max(right,max(up,down))) + grid[i][j];
    }
};