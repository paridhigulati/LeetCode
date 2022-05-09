class Solution {
    
    private : 
    
    bool isPalin(string s)
    {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        return tmp == s;
    
    }
    
public:
    
    void solve(string s, vector<vector<string>>& ans, vector<string>partitions)
    {
        
     // base case 
        if(s.size()== 0)
        {
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
        
        string prefix = s.substr(0, i+1);
        if(isPalin(prefix))
        {
        partitions.push_back(prefix);
        
        solve(s.substr(i+1), ans, partitions);
        
            partitions.pop_back();
        }
        }
        
    }
    

    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>partitions;
        
        solve(s, ans, partitions);
        
        return ans;
    }
};