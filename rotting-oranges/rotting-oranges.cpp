
        
      /*  vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j}); // push all rotten oranges into queue
                if(grid[i][j]==1)
                    fresh++;        // count of fresh oranges
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int row=p.first+dir[i];
                    int col=p.second+dir[i+1];
                    if(row>=0 && row<m && col>=0 && col<n &&grid[row][col]==1)
                    {
                        grid[row][col]=2;
                        q.push({row,col});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};
   */
          
         struct node {
             int x,y,time;
             node(int _x, int _y, int _time)
             {
                 x = _x;
                 y = _y;
                 time = _time;
             }
         };
          class Solution {
          public:
     
           int orangesRotting(vector<vector<int>>& grid) 
          {
               int n = grid.size();
               int m = grid[0].size();
               int cnt = 0 ;
               int counter=0;
               queue<node>q;
               //push the rotten oranges
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        if(grid[i][j]==2)
                            q.push(node(i,j,0));
                        if(grid[i][j]!=0)
                            cnt++; // counting non empty cells
                    }
                }
                    int ans=0;
                    while(!q.empty())
                    {
                        int x = q.front().x;
                        int y =q.front().y;
                        int time= q.front().time;
                        q.pop();
                        counter++;
                        ans = max(ans,time);
                        // iterate in all directn
                        int dx[] = { -1, 0, 1,0};
                        int dy[] = { 0,1,0,-1};
                        for(int i=0;i<4;i++)
                        {
                            int newX = x + dx[i];
                            int newY = y +dy[i];
                            if(newX >= 0 and newX <n and newY >=0 and newY < m and grid[newX][newY]==1 ) // fresh orange 
                            {
                                grid[newX][newY] = 2; // rot it 
                                q.push(node(newX , newY, time+1));
                            }
                            
                        }
                    }
                    if(counter== cnt) return ans;
                 return -1;
                  }
               
           };
    