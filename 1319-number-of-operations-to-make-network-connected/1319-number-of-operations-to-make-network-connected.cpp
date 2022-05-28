class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& connections, vector<bool>& vis, int n)
    {
        
        vis[node]=true;
        
        for(int i : connections[node])
        {
            if(!vis[i])
                dfs(i, connections, vis,n);
        }
    }
        
        
        
        
        
        
    
    int makeConnected(int n, vector<vector<int>>& connections) {
     
        vector<bool>vis(n, false);
        int count =0;
        vector<vector<int>>adj(n);
    
        if(connections.size() < n-1)
          return -1;
        
            for(auto itr : connections)
        {
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, adj, vis,n);
            }
        }
        return count-1;
    }
};
