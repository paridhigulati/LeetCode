class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j)
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

    int numIslands(vector<vector<char>>& grid) {
       
        int r=grid.size();
        int c = grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '1'){
                     bfs(grid,i,j);
                    ans++;
                   
                }
            }
        }
        return ans;
    }
    
    
    
};