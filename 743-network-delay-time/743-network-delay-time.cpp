class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
     
         vector<pair<int,int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]}); //we have stored the data in adj list
        }
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minh; //minheap (wt, node)
        vector<int> mintime(n+1, INT_MAX);
        mintime[src] =0;
        minh.push({0,src});
        
        while(minh.size()!=0){
            auto topnode = minh.top();
            int nod = topnode.second;
            int t = topnode.first;
            minh.pop();
            
            for(int i=0; i<adj[nod].size(); i++){
                
                if(mintime[adj[nod][i].first] > t + adj[nod][i].second){
                    mintime[adj[nod][i].first] = t+ adj[nod][i].second;
                    minh.push({mintime[adj[nod][i].first], adj[nod][i].first});
                }
            }
            
        }
        int anstime = -1;
        for(int i=1; i<mintime.size(); i++){    //we are starting it from 1 bcz 0th index is dummy and nodes are named from 1---n
            anstime = max(anstime, mintime[i]);
        }
        if(anstime == INT_MAX) return -1;
        return anstime;
    }
};
  