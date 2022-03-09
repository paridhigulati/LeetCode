class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node)
    {
        vis[node] = true;
        for(int i : adj[node])
        
               if(!vis[i])
                dfs(adj, vis, i);
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        //for n components we need atleast n-1 edges
              if(connections.size() < n - 1)
            return -1;

        vector<vector<int>>adj(n);
        
      for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int component=0;
        vector<bool>vis(n,false);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(adj, vis, i);
                component++;
            }
        }
        return component-1;
    }
    
};