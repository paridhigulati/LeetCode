class Solution {
public:
     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	int n = grid1.size(),m=grid1[0].size();
	vector<vector<int>> vis(n, vector<int>(m));
	int res = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++){
			if(grid2[i][j] == 1 && vis[i][j]==0){
				if(bfs(grid1,grid2,vis,i,j,n,m)) {
					res++;
				}
			}
		}
	}
	return res;
}
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis, int i,int j,int n, int m) {
	queue<pair<int, int>> q;
	q.push({i,j});
	vis[i][j] = 1;
	bool res = true;
	while(!q.empty()) {
		int r = q.front().first, c = q.front().second;
		if(grid1[r][c] == 0) res=false;
		q.pop();
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};

		for(int i = 0; i < 4; i++) {
			int newX = dx[i] + r;
			int newY = dy[i] + c;

			if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid2[newX][newY] == 1 && vis[newX][newY] == 0) {
				q.push({newX, newY});
				vis[newX][newY] = 1;
			}
		}
	}   
	return res;
}
};   
   