class Solution {
public:
      void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 ||i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return; // boundary wale 
          if(grid[i][j]!='O') return;
        grid[i][j]= '#'; // boundary wale connected components ko zero krdo
        dfs(i+1,j,grid); 
        dfs(i,j+1,grid);
        dfs(i-1,j,grid);
        dfs(i,j-1,grid);
    }
    
    void solve(vector<vector<char>>& board) {
     
        // identify all the boundary zeroes, perform a dfs and mark all its connected zeroes as # , in this way we get all the invalid zeroes
        // now iterate again and only valid zeroes are left, mark them as x 
   
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
  
        
      
     int m = board.size(); 
     int n = board[0].size();
     
         for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
       if(i==0 ||j==0 || i==m-1 || j==n-1) {
              dfs(i,j,board);
       }
          }
         }
    //now iterating over the matrix and if cell = x (valid) flip them else change to zero 
     for(int i=0; i<m; i++)
     for(int j=0; j<n; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == '#')
                 board[i][j] = 'O';
         }
    }      
    
};