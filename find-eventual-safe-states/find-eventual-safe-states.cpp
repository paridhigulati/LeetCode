class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        
        // return nodes which are not part of the cycle 
        // safe_nodes , cycle_nodes 
        
            vector<int> res;  //for storing the result
        
        vector<int>visited(graph.size(), false);//for keeping track of the visited nodes 
        vector<int> checked(graph.size(), false); // for checking if loop exists , if this will be true and of we reach again to this node then there is cycle
        
        for(int i = 0; i < graph.size(); i++) { 
            if(!checkcycle(i, graph, visited, checked)) { 
                res.push_back(i);//check for each node
            } 
        }
        return res;
    } 
    
    bool checkcycle(int node, vector<vector<int>>& graph, vector<int> &visited,vector<int> &checked) { 
        
        visited[node] = true; //mark both true
        checked[node]= true; // implies if by any other node if the path comes to the same node we are currently at ,,then there is a cycle
        //dfs traversal
        for(int i = 0;i< graph[node].size();i++) { 
            if(!visited[graph[node][i]]) { 
                if(checkcycle(graph[node][i], graph, visited, checked)) { 
                    return true;
                }
            } else if(checked[graph[node][i]]) { 
                return true;//if checked vale is true and visited is also true means we are at the node which is already in a loop hence there is a cycle
            }
        } 
        
        checked[node] = false; //when leaving this node mark it as false
        
        return false;
    }
};
        
    