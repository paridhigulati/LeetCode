class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     
        int n=grid.size(), m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    
    void bfs(vector<vector<char>>& grid, int i, int j)
    {
        
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        vector<vector<int>>dir = { {0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto i : dir)
            {
                int nrow = row + i[0];
                int ncol = col + i[1];
                
                if(nrow>=0 and nrow < n and ncol >=0 and ncol <m and grid[nrow][ncol]=='1' )
                {
                    q.push({nrow, ncol});
                    grid[nrow][ncol]='0';
                }
            }
        }
    }
};