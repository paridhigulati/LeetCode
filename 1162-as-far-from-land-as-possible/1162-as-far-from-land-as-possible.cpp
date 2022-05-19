class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
     
     	int locMax = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1)
                    q.push({ i, j });
			}
		}

		while (!q.empty()) {
			//pair<int, int> cur = q.front();
            int row = q.front().first;
            int col = q.front().second;
			q.pop();
			vector<vector<int>>dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
			for (auto dir : dirs) {
				int nx = row + dir[0];
				int ny = col + dir[1];
                
				if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
					q.push({ nx, ny });
					grid[nx][ny] = grid[row][col] + 1;
					locMax = max(grid[nx][ny], locMax);
				}
			}
		}
		//return (locMax > 0 ? locMax-1 : -1);
        return locMax-1;
	}
};