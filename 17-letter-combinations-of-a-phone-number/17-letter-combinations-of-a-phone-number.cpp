class Solution {
public:
    
    
    void getComb(string mp[], string digits, int index, string tmp, vector<string>& ans)
    {
        
        //base case
        if(index >= digits.size())
        {
            ans.push_back(tmp);
            return;
        }
        int number = digits[index]-'0';
        string val = mp[number];
        
        for(int i=0;i<val.size();i++)
        {
            tmp.push_back(val[i]);
            getComb(mp, digits, index+1, tmp, ans);
            tmp.pop_back();
        }
        
        
        
        
    }
    vector<string> letterCombinations(string digits) {
        
        string mp[10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans ;
        int index = 0;
        string tmp; 
        if(digits == "") return ans;
        
        getComb(mp, digits, index, tmp, ans);
        
        return ans;
        
    }
};