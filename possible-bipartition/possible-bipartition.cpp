class Solution {
public:
       // 0 -> not colored  , 1->blue, -1 -> red 
    
    bool isBipartite(vector<vector<int>> &adj, int N, int node, vector<int> &color)
    {
        queue<int>q;
        q.push(node); //pushing the starting node and assuing its colored
        color[node]=1;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int child : adj[curr]) // travelling all its adjacent nodes 
            {
                if(color[child]==color[curr]) // if they have same color so that means it has odd cycle
                    return false;
                if(color[child]==-1) // unvisited 
                {
                    color[child] = 1-color[curr];
                    q.push(child);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) { // no. of people and array of pairs 
     //we need to make adjacency list so 
        vector<vector<int>>adj(N+1);
        //undirected graph so pushing back twice
        for(int i=0;i<dislikes.size();i++){
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
          adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(N+1,-1);
        for(int i=1;i<=N;i++) // this loop will check in case of multicomponent
        {
            if(color[i]==-1) // if the node is uncolored call bfs on it
                if(!isBipartite(adj,N,i,color))
              return false;
        }
         
    
        
        
 return true;
    }
};