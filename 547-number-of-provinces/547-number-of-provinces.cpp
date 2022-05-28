class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, int node, vector<bool>& vis)
    {
        
        vis[node] = true;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[node][i]==1 and !vis[i])
            dfs(isConnected, i, vis);
            
        }
    }
        
  
    
    int findCircleNum(vector<vector<int>>& isConnected) {
     //find number of connected components 
        
        int count = 0;
        vector<bool>vis(isConnected.size(), false);
        
        if(isConnected.size() == 0) return 0;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i])
            {
                dfs(isConnected, i, vis);
                count++;
        }
    }
        return count;
    }
};