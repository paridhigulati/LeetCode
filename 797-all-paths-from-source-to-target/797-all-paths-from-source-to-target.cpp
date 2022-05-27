class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       
        vector<vector<int>> ans;
        vector<int>path;
        
        dfs(graph, ans, path, 0);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int node)
    {
        path.push_back(node);
    
    if(node == graph.size()-1)
        ans.push_back(path);
    else
        for(int i : graph[node])
        {
            dfs(graph, ans, path, i);
             path.pop_back();
            
        }
    //backrack
}
};


 