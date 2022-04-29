class Solution {
public:
    
  /* the graph is bipartite if and only if the two ends of each edge must have opposite colors. Therefore, we could just start with standard BFS to traverse the entire graph and

color neighbors with opposite color if not colored, yet;
ignore neighbors already colored with oppsite color;
annouce the graph can't be bipartite if any neighbor is already colored with the same color.
NOTE: The given graph might not be connected, so we will need to loop over all nodes before BFS.*/

  bool isBipartite(vector<vector<int>>& graph) {
 
      int n = graph.size();
      vector<int>color(n);
      queue<int>q;
      for(int i=0;i<n;i++)
      {
         q.push(i);
          
         if(color[i]) // already colored
          continue;
          
          color[i] = 1;
          while(!q.empty())
          {
              int curr = q.front();
              
              for(auto itr : graph[curr])
              {
                  if(!color[itr])
                  {
                      color[itr] = -color[curr];
                      q.push(itr);
                  }
                  else if (color[itr]==color[curr])
                  {
                      return false;
                  }
              }
              q.pop();
          }
         
      }
       return true;
  }
};