class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                   bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    void bfs(int i, int j, vector<vector<char>>& grid)
    {
      int n = grid.size();
        int m = grid[0].size();
        
         queue<pair<int,int>>q;
        
         q.push(make_pair(i,j));
        
        grid[i][j]= '0'; 
    
        vector<vector<int>>dir = { {0,1}, {1,0}, {0,-1}, {-1,0}};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
           // q.pop();
            for(auto itr : dir)
            {
                  int nrow = row + itr[0];
                int ncol = col + itr[1];
                
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol <m and grid[nrow][ncol] =='1')
                {
                    grid[nrow][ncol] = '0';
                    q.push((make_pair(nrow, ncol)));
                    
                }
            }
            q.pop();
        }
}
};
    
   