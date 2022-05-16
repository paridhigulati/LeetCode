 
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        return bfs(grid, n);
    }
    int bfs(vector<vector<int>>& grid, int n)
    {
      if(grid[0][0] == 1 || grid[n-1][n-1]==1)return -1;
        
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        vector<vector<int>>dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};

        grid[0][0] = 1;
        while(!q.empty())
        {
        
        int row = q.front().first;
        int col = q.front().second;
        
        if(row == n-1 and col == n-1) return grid[row][col];
        
        for(auto i : dir)
        {
            int nRow = row + i[0];
            int nCol = col + i[1];
        
        if(nRow >= 0 and nRow <n and nCol >=0 and nCol < n and grid[nRow][nCol]==0)
        {
            q.push(make_pair(nRow, nCol));
            grid[nRow][nCol] = grid[row][col] + 1;
        }
        }
        
        q.pop();
        }
    return -1;
}
};