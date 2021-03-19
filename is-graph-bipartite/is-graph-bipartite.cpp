class Solution {
public:
    
    
    
    
    //DFS  TIME  O(V+E)   SPACE O(V)
    
 // -1 = color hasn't applied yet
// 0 = red
//1 = Blue

/*   vector<vector<int>>adj;
    int vis[101];
    
    int dfs(int node, int color){
        if(vis[node]!=-1){
            if(vis[node]==(1^color))return 1;
            else return 0;
        }
        vis[node]=color;
        for(auto x:adj[node]){
            if(dfs(x,color^1))return 1;
        }
        return 0;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        this->adj=graph;
        memset(vis,-1,sizeof vis);
        for(int i=0;i<graph.size();i++){
            if(vis[i]!=-1)continue;
            if(dfs(i,0))return 0;    
        }
        return 1;
    }
};
*/
    
    //BFS 
    
    /*color neighbors with opposite color if not colored, yet;
ignore neighbors already colored with oppsite color;
annouce the graph can't be bipartite if any neighbor is already colored with the same color.
NOTE: The given graph might not be connected, so we will need to loop over all nodes before BFS. */

  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (int neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
  }
};