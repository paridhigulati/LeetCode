class Solution {
public:
    
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& vis)
    {
        vis[src] = true;
        	//if(n==0) return 0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(isConnected[src][i]==1 and !vis[i])
                dfs(i,isConnected, vis);
        }
       	
        
        
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n  = isConnected.size() ;
        	if(n==0) return 0;
        vector<bool>vis(n, false);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, isConnected, vis);
        }
        }
        return count;
    }
};