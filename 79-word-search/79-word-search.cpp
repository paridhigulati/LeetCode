class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
     
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] and dfs(board,word,i,j,0 ))
                    return true;
            }
        }
        return false;
        
    }
    
    
   bool dfs(vector<vector<char>>& board, string word, int i, int j, int count)
    {
        if(word.size()==count)
            return true;
        if(i<0 || j<0 || i>=board.size()|| j>=board[0].size()|| board[i][j]!=word[count])
            return false;
        
        board[i][j]='*';
        
        bool found = dfs(board, word, i+1,j,count+1) || dfs(board, word, i-1,j,count+1)||dfs(board, word, i,j+1,count+1)||dfs(board, word, i,j-1,count+1);
       
       // backtrack so change the character back for other searches
       board[i][j] = word[count];
       
       return found;
    }
};