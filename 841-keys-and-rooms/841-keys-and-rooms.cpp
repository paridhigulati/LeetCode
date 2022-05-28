class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
        int count =0, n = rooms.size();
        vector<bool>vis(n, false);
        

            dfs(0, n, rooms, vis);
                for(int i=0;i<n;i++)
        for(int i=0;i<n;i++)
        {
        if(!vis[i])
        
           return false;
        }
        
        
        return true;
    }
    
    void dfs(int node, int n, vector<vector<int>>& rooms, vector<bool>& vis)
    {
      vis[node] = true;
        for(auto it : rooms[node])
        {
            if(!vis[it])
                dfs(it,n, rooms,vis);
        }
    }
};