class Solution {
public:
    int ans= 0;
    
    void countIslands(int i,int j,int &m,int &n ,vector<vector<int>>& grid,int &count) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != 1 ) 
            return;
        count++;
        grid[i][j] = 2;
        countIslands(i+1,j,m,n,grid,count);
        countIslands(i-1,j,m,n,grid,count);
        countIslands(i,j+1,m,n,grid,count);
        countIslands(i,j-1,m,n,grid,count);     
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {    
                    int count = 0;
                    countIslands(i,j,m,n,grid,count); 
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};