class Solution {
public:
    
    
    //shortest path - with no weights -> ( bfs always)
    //shortest path - with weights as 0/1 - > (0/1 bfs always)
    //shortest path - with any weights( without -ve edge cycle) ->dijkstra always
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size(), m = maze[0].size();
        queue<pair<int,int>>q;
        int dist = 0;
        q.push(make_pair(entrance[0], entrance[1]));
        
        vector<vector<int>>dir = { {0,1} , {-1,0}, {1,0}, {0,-1}};
         maze[entrance[0]][entrance[1]]='+';
        while(!q.empty())
        {
            int size=q.size();
            
            while(size--){
            int row = q.front().first;
            int col = q.front().second;
           // maze[row][col]='+';
            q.pop();
            
            for(auto it : dir)
            {
                int nrow = row + it[0];
                int ncol = col + it[1];
                
                 if(nrow<0||nrow>=n||ncol<0||ncol>=m)  {
                     if(dist)
                     return dist;
                        continue;                             
                     }
                   
                if(nrow  >= 0 and nrow < n and ncol >=0 and ncol < m and maze[nrow][ncol] == '.' )
                {
                    q.push(make_pair(nrow, ncol));
                    maze[nrow][ncol]= '+';
                }
            }
            }
        dist++;    
        }
        
        return -1;
        
       
    }
};