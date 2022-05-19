class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>>q;
        vector<vector<int> > dis(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push(make_pair(i,j));
                    dis[i][j] = 0;
                }
            }
        }
               
                    
        vector<vector<int>>dir = { {0,1}, {0,-1}, {-1,0}, {1,0}};
        
      while(!q.empty())
      {
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          for(auto it : dir)
          {
              int nrow = row + it[0];
              int ncol = col + it[1];
              
              if(nrow >=0 and nrow < m and ncol >=0 and ncol < n and mat[nrow][ncol] == 1 and dis[nrow][ncol] == -1)
              {
                  dis[nrow][ncol]= 1+ dis[row][col];
                  q.push(make_pair(nrow, ncol));
              }
          }
      }
                return dis;
    }
};