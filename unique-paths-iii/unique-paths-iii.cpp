/*
       Explanation:
First step, we need to know where the starting point is. We also want to know the number of empty cells.
So we iterate through the grid, count empty cells and save the starting point - start_x and start_y.
Now, we do classic DFS, marking the visited cells with -1 and counting the cells we passed.
If we reached the ending point and we passed empty number of cells - this means we passed by every non-obstacle cell.
*/
class Solution {
public:
    int res = 0, empty = 1;
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(empty == count) res++; 
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x, start_y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) start_x = i, start_y = j;
                else if (grid[i][j] == 0) empty++;
            }
        }
        
        dfs(grid, start_x, start_y, 0);
        return res;
    }
}; 


/*37. Sudoku Solver - https://leetcode.com/problems/sudoku-solver/
79. Word Search - https://leetcode.com/problems/word-search/
1219. Path with Maximum Gold - https://leetcode.com/problems/path-with-maximum-gold/
(Premium) 1820. Maximum Number of Accepted Invitations - https://leetcode.com/problems/maximum-number-of-accepted-invitations/

Also if you want to know the difference between DFS and Backtracking, take a look at the first comment :
https://leetcode.com/discuss/general-discussion/136503/what-is-difference-between-backtracking-and-depth-first-search */