class Solution {
public:
vector<vector<bool>> vis;
         int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, m, n, cnt = 0;
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    m = size(grid1), n = size(grid1[0]);
    vis.resize(m, vector<bool>(n));
	// iterate over all the cells and start a dfs from unvisited land cell
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++) 
            if(!vis[i][j] && grid2[i][j]) {   // start a dfs search for island consisting of cell (i,j) in grid2
                bool ans = true;
                if(dfs(grid2, grid1, i, j, ans)) cnt++;
            }
    return cnt;
}
bool dfs(vector<vector<int> >& grid2,vector<vector<int> >& grid1, int i, int j, bool& ans) {
    if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid2[i][j] == 0) return true;        
    if(grid1[i][j] == 0) ans = false;  // if any of island cell for current island of grid2 is not present in grid1
    vis[i][j] = true;                  // mark visited for each land cell so that we don't repeat it again
    for(int k = 0; k < 4; k++) 
        dfs(grid2, grid1,i + moves[k][0], j + moves[k][1], ans);
    return ans;
}
};