class Solution {
public:
    int count=0;
        void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
        {
            count++; return;  //count no. of side surrounded by water
        }
        if(grid[i][j]==-1) //already visited
            return;
        grid[i][j] =-1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
     
        
        
        // count the sides surrounded by water
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid, i,j); 
                    break; //cuz acc to ques only 1 connected c omponent is there
                }
                
            }
        }
        return count;
    }

};