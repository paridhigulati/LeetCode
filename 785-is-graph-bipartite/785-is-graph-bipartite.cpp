class Solution {
public:
    
  /* the graph is bipartite if and only if the two ends of each edge must have opposite colors. Therefore, we could just start with standard BFS to traverse the entire graph and

color neighbors with opposite color if not colored, yet;
ignore neighbors already colored with oppsite color;
annouce the graph can't be bipartite if any neighbor is already colored with the same color.
NOTE: The given graph might not be connected, so we will need to loop over all nodes before BFS.*/

  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
     // for (q.push(i); !q.empty(); q.pop()) {
        q.push(i);
        while(!q.empty()){
            
        int cur = q.front();
        for (int neighbor : graph[cur]) //checking for neighbours of curr
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        } 
            q.pop();
      }
    }
    
    return true;
  }
};