class Solution {
public:
    vector<int>adj[50005];
    int minReorder(int n, vector<vector<int>>& connections) {
        
        // int n = connections.size();
        //vector<int>adj(n);
        vector<bool>vis(n, false);
        set<pair<int,int>>st;
        
        for(int i=0;i<connections.size();i++)
        {
              
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
            st.insert({connections[i][0], connections[i][1]});
            
        }
        queue<int>q;
        q.push(0);
        int cnt = 0;
        
        while(!q.empty())
        {
            int row = q.front();
            q.pop();
            if(!vis[row])
            {
                vis[row]=true;
            
            for(int i=0;i< adj[row].size();i++)
            {
                q.push(adj[row][i]);
                if(!vis[adj[row][i]] and st.count({row, adj[row][i]}))
                    cnt++;
            }
            }
        }
        return cnt;
        
    
        
    }
};
//  vector<int>adj[50005];
//         bool visited[50005];
//         set<pair<int,int>>s;
//     int minReorder(int n, vector<vector<int>>& con) {
//         memset(visited,false,sizeof(visited));
//         for(int i=0;i<con.size();i++){
//             adj[con[i][0]].push_back(con[i][1]);
//             adj[con[i][1]].push_back(con[i][0]);
//             s.insert({con[i][0],con[i][1]});
//         }
//         queue<int>q;
//         q.push(0);
//         int total=0;
//         while(!q.empty()){
//             int k=q.front();
//             q.pop();
//             if(!visited[k]){
//                 visited[k]=true;
//                 for(int i=0;i<adj[k].size();i++){
//                     q.push(adj[k][i]);
//                     if(!visited[adj[k][i]] && s.count({k,adj[k][i]})){
//                         total++;
//                     }
//                 }
//             }
//         }
//         return total;
//     }
// };