class Solution {
public:
    
    vector<vector<string>>ans;

        vector<vector<string>> solveNQueens(int n) {
     	vector<string> board(n, string(n, '.'));  // creating an empty board

         solve(0, board);
        return ans;
    }
    
    bool isSafe(vector<string>& board, int row, int col)
    {
        int n = board.size();
        //all 4 diagonals and boundary condition 
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == 'Q' ) return false;
            
	if(row+i < n and col+i < n and board[row+i][col+i]=='Q') return false;
	if(row-i >= 0 and col-i >=0 and board[row-i][col-i]=='Q') return false;            
	if(row-i>=0 and col+i < n and board[row-i][col+i] == 'Q') return false;
	if(row+i <n and col-i >=0 and board[row+i][col-i] == 'Q') return false;
	}
	return true;

}
    

    void solve(int row,  vector<string>& board)
    {
        int n = board.size();
         if(n == row) 
         {
             ans.push_back(board);
             return;
         }
        
        for(int col=0; col< board.size();col++)
        {
            if(isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                solve(row+1, board);
                board[row][col] = '.';
            }
        }
    }
};
    
    
  
