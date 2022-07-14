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
                    
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
    
        
        void bfs(int i, int j, vector<vector<char>>& grid){
                 
         int n = grid.size();
        int m = grid[0].size();
                    vector<vector<int>>dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        
         queue<pair<int,int>>q;
            
        q.push({i,j});
            grid[i][j] = '0';
            
        while(!q.empty())
        {
            
                auto it = q.front();
                q.pop();
                
                for(auto itr : dir)
                {
                   
                    int x = it.first + itr[0];
                    int y = it.second + itr[1];
                    
                    if(x>=0 and x<n and y>=0 and y<m and grid[x][y] == '1')
                    {
                        grid[x][y]='0';
                        q.push({x,y});
                    }
                }
            
        }
        
    }
};