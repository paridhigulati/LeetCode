class Solution {
public:
    
    void dfs(string src, string dst, map<string, vector<pair<string, double>>>&mp, set<string>vis, double &ans, double tmp )
    {
        
        
        if(vis.find(src) != vis.end())
            return; //already visited 
        vis.insert(src); 
        
        if(src==dst) {
        ans = tmp; 
        return;
        }
        else
        {
            for(auto it : mp[src])
            {
               // if(vis.find(it) == vis.end())
                    double tmp1 = tmp;
                     tmp  *= it.second; 
                    dfs(it.first, dst, mp, vis, ans, tmp);
                     tmp = tmp1; //backtrack for next call 
            }
        }
        
  
        
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& q) {
     
        
        map<string, vector<pair<string,double>>>mp;
        
        for(int i=0;i<e.size();i++)
        {
            mp[e[i][0]].push_back({e[i][1], values[i]}); //build graph
            mp[e[i][1]].push_back({e[i][0], 1/values[i]}); //build graph

        }
        vector<double>res;
        
        for(int i=0;i<q.size();i++)
        {
            string  src = q[i][0];
            string dst = q[i][1];
            set<string>vis;
            double ans = -1.0;
            
            if(mp.find(src) != mp.end())
            dfs(src, dst, mp, vis, ans, 1.0);
        
        res.push_back(ans);
        }
        return res;
    }
};