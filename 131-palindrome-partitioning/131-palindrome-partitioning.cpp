class Solution {
public:
    
    bool isPalin(string s)
    {
        int l=0, r= s.size()-1;
        while(l<r)
        {
            if(s[l++] != s[r--])
            return false;       
        }
        return true;
    }
    
    void solve(string s, vector<string>temp, vector<vector<string>>& res )
    {
        if(s.size()==0) res.push_back(temp);
        
        for(int i=0;i<s.size();i++)
        {
            string leftPart = s.substr(0,i+1);
            if(isPalin(leftPart))
            {
                temp.push_back(leftPart);
            solve(s.substr(i+1), temp, res);
            temp.pop_back();
            }
        }
        
    }
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        solve(s,temp,res);
        return res;
        
        
    }
};