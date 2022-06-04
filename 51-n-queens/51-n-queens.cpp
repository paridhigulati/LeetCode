class Solution {
public:
    vector<vector<string>>ans;
    
    
    bool isValid(vector<string>& board, int row, int col)
    {
      	int n = board.size();
	//same row
	     for(int i = col; i >= 0; --i)
	     	if(board[row][i] == 'Q')
			return false;

      // upper left diagonal
	for(int i = row, j = col; i >= 0 && j >= 0 ; --i, --j)
		if(board[i][j] == 'Q')
			return false;

   // bottom left diagonal
	for(int i = row, j = col; i < n && j >= 0; ++i, --j)
		if(board[i][j] == 'Q')
			return false;
	
	return true;      



        
        
    }
    void dfs(int col, vector<string>& board)
    {
        if(col >= board.size())
        {
            ans.push_back(board);
            
        }
        
        for(int i=0;i<board.size();i++)
        {
            if(isValid(board, i, col))
            {
                board[i][col] = 'Q';
                dfs(col+1, board);
                
                board[i][col] = '.';
            }
        }

    }

    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
          dfs(0, board);
         return ans;
    }
};



