class Solution {
public:
          // boundary par jitne bhi connected components h usko hata do, bache hue jo h vo ans 
     // last row, col and 1
       
    //dfs call krke coundary se sare connected components ko 0 krdo aur fir jitne bache hue 1 rhe gye usko count krlo
 
     void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 ||i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return; // boundary wale 
        grid[i][j]=0; // boundary wale connected components ko zero krdo
        dfs(i+1,j,grid); 
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
       if(i==0 ||j==0 || i==grid.size()-1 || j==grid[0].size()-1) {
              dfs(i,j,grid);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) ans++; // grid mai jine bhi 1 bache h vo ans
            }
        }
        return ans;
    }
};
