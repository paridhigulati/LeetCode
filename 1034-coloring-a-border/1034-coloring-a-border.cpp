class Solution {
public:
        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(vector<vector<int>>& grid, int row, int col, int color)
    {
        grid[row][col] = -color; //mark visited
        int count=0;
        
        //check for connected comp in 4 directions
        for(int i=0;i<4;i++)
        {
      // not connected comp or invalid

             int Nrow = row + dir[i][0];
            int Ncol = col + dir[i][1];
            
  if(Nrow < 0 || Ncol < 0 || Nrow >= grid.size() || Ncol >= grid[0].size()|| abs(grid[Nrow][Ncol])!=color)
            {
                continue;
            }
      
        //else connected comp 
        count++;
 if(grid[Nrow][Ncol]==color) // color positive h yani unvisited to dfs call 
                
            {
                dfs(grid,Nrow, Ncol, color);
            }
        }
        // if(grid[nRow][nCol]==color) // unvisited
        //     dfs(grid, nRow, nCol,  color);
        // }
        //edge case -> while backtracking if we find all 4 directions having same color, uncolor it
        if(count==4)
            grid[row][col]=color; // unvisit and backtrack
        
        
        
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
     
        
        dfs(grid,row, col, grid[row][col]);
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] < 0) //connected components hence color them
                 
                    grid[i][j] = color;
            }
        }
        return grid;
    }
};