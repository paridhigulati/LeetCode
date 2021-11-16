class Solution {
public:
     
    
    bool dfs(vector<vector<int>>& grid, int i, int j)
    {
        int m = grid.size();
      int n= grid[0].size();
        if(i<0 || j<0|| i>=m||j>=n)
            return false;
        
        if(grid[i][j] == 1)
            return true;
        grid[i][j]=1;
        bool up = dfs(grid, i-1,j);
        bool down = dfs(grid, i+1, j);
        bool left = dfs(grid, i , j-1);
        bool right = dfs(grid, i, j+1);
        
        return up and down and left and right;
    }
    int closedIsland(vector<vector<int>>& grid) {
     
      int count=0;
         int m = grid.size();
      int n= grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0 and dfs(grid,i,j))
                    count++;
            }
        }
        return count;
    }
};