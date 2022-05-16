class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
         int m = image.size();
        int n = image[0].size();
        
        int color = image[sr][sc];
        
      if(image[sr][sc] == newColor) return image;
        
        vector<vector<int>>dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        queue<pair<int,int>>q;
        q.push(make_pair(sr, sc));
        
        image[sr][sc] = newColor;
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            
        
        for(auto i : dir)
        {
            int nrow = row + i[0];
            int ncol = col + i[1];
            
            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and image[nrow][ncol] == color)
            {
                 image[nrow][ncol] = newColor;
                q.push(make_pair(nrow, ncol));
               
            }
        }
            q.pop();
    }
        return image;
    }
};
 
        
     
            
     