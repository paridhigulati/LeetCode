//shortest paths-unweighted graph---->bfs(very standard)
//but usually 1 source node---minimum distance from that particular node
//but here multiple source nodes
//so push all of them first
//WHY???
//WHEN WE POP AND EXPLORE WE ARE DOING SO IN INCREASING ORDER OF THEIR LEVELS
//SO WHEN WE DISCOVER A NODE FIRST WE ARE EXPLORING IT FROM MINI POSSIBLE LEVEL NODE THAT IT IS CONNECTED TO
//first the source..then level 1 nodes..then level 2 and so on
//here the case is there are many level 0 nodes
//so push all of them first!!!
class Solution {
    public:
    

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
		
		//Make a visited array to keep track of visited positions
        vector<vector<bool>> visited(m, vector<bool>(n, false));
		
		//Store position at which value is 0, and search by BFS to find nearest 1
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(mat[i][j]==0)
                    q.push({i, j});
        
        int level=0;    //To store the nearest distance from position of 0 in queue to nearest 1
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
				//If we already visited the node, leave it, else mark it as true
                if(visited[i][j])
                    continue;
                visited[i][j]=true;
                
                if(mat[i][j]==1)
                    mat[i][j]=level;
                
				//Traverse in all four directions from the current position
                int temp[] = {-1,0,1,0,-1};
                for(int k=0;k<4;k++)
                {
                    int x = i + temp[k];
                    int y = j + temp[k+1];
                    
                    if(x<0 || y<0 || x==m || y==n)
                        continue;
                    q.push({x, y});
                }
            }
            level++;
        }
        return mat;
    }
};