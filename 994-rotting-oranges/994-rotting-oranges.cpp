class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
  
        int row = grid.size(), col = grid[0].size();
        
        int fresh=0, time=-1;
        
        queue<pair<int,int>>q;
                vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates

        //vector<vector<int>>dir = { {0,1}, {1,0}, {-1,0}, {0,-1}};
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                 if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        
        while(!q.empty())
              {
            int size = q.size();
                  for(int i=0;i<size;i++)
                  {
                      auto  front = q.front();
                      q.pop();
                      
                      for(int i=0;i<4;i++)
                      {
                          int x  = front.first + dir[i];
                          int y = front.second + dir[i+1];
                          
                          if(x >=0 and x <row and y>=0 and y<col and grid[x][y]==1)
                          {
                              fresh--;
                              grid[x][y] = 2;
                              q.push({x,y});
                          }
                      }
                  }
        
              time++;
        }
    
        if(fresh > 0) return -1;
        
        if(time ==-1) return 0;
        
        return time;
    }
};