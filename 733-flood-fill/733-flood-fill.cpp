class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        queue<pair<int,int>>q;
        int color = image[sr][sc];
        q.push(make_pair(sr,sc));
       int n = image.size();
        int m = image[0].size();
        
          if(image[sr][sc] == newColor) return image;
        
        image[sr][sc] = newColor;
        vector<vector<int>>dir = { {0,1}, {0,-1}, {-1,0}, {1,0}};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
             q.pop();
            
           for(auto it : dir)
           {
               int nrow =row + it[0];
               int ncol = col + it[1];
               
               if(nrow >= 0  and nrow < n and ncol >=0 and ncol< m and image[nrow][ncol] ==color)
               {
                   image[nrow][ncol] = newColor;
                   q.push(make_pair(nrow, ncol));
               }
           }
        }
       
        return image;
    }
};
        
    