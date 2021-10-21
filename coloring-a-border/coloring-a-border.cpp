class Solution {
public:
    
     
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
          dfs(grid, row, col, grid[row][col]);
          for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0){
                 grid[i][j] = color;
                }
                    
            }
        }
      return grid;
    }

  vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid, int row, int col, int color)
    {
        grid[row][col] = -color;
        int count =0;
        for(int i =0;i<4;i++)
        {
            int Nrow = row + dir[i][0];
            int Ncol = col + dir[i][1];
            
            if(Nrow < 0 || Ncol < 0 || Nrow >= grid.size() || Ncol >= grid[0].size()|| abs(grid[Nrow][Ncol])!=color)
            {
                continue;
            }
            count++; // not out of bound and same color, hence connected 
            // ab check krna h vis hai ya nhi 
            
            if(grid[Nrow][Ncol]==color) // color positive h yani unvisited to dfs call 
                
            {
                dfs(grid,Nrow, Ncol, color);
            }
            
        }
        if(count==4) 
       grid[row][col] = color; // no further dfs call possible, so mark it unvisited and bcktrack 
    }
    
};