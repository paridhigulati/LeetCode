
    
         /*         // 0 -> not colored  , 1->blue, -1 -> red 
    bool isValid(vector<vector<int>>graph, vector<int>color, int curr, int node )
    {
     // check if its already colored 
        if(color[node]!=0)
            return color[node] == curr;
       
        color[node] = curr;
        
        // to check for its adjacent nodes
        for(int child : graph [node])
        {
            if(!isValid(graph, color, -curr, child))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>color; // to store all the colors 
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==0 && !isValid(graph,color, 1, i))
            
                return false;
         }
        
            return true;
      
    }
};
*/
    class Solution {
public:
    vector<int>vis,col;
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(int child:graph[v]){
            if(vis[child]==0){
                // here c^1 is for flipping 1 by 0 or 0 by 1, that is flip the current color
                if(dfs(child,c^1,graph)==false) 
                    return false;
            }
            else{
                if(col[v]==col[child])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);

        for(int i=0;i<n;++i){
            if(vis[i]==0 && dfs(i,0,graph)==false){ 
                return false;
            }
        }
        
        return true;
    }
};