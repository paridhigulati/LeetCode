class Solution {
public:
    bool solve(string s1, string s2, string s3,  unordered_map<string,bool>& dp) {
         //edge  case -> abcd aefg => how to determine which a came first in string
       
        
        
        if(s1.empty() and s2.empty() and s3.empty()) return true;
        
        if(s3.empty()) return false;
        
        string str = s1 + "|" + s2 + "|" + s3;
        if(dp.count(str)) return dp[str]; 
        //case 1 : s1+s2 
        bool first = (!s1.empty() and s1[0] == s3[0]) and solve(s1.substr(1), s2, s3.substr(1), dp); 
        // abcd, aefg => aabecfdg ===> bcd, abecfdg 
        bool second = (!s2.empty() and s2[0] == s3[0]) and solve(s1, s2.substr(1), s3.substr(1), dp);
        
        return dp[str] =  first || second; 
    }
        
            bool isInterleave(string s1, string s2, string s3) {
                {
                    unordered_map<string,bool>dp;
                   return solve(s1,s2,s3,dp);
                }
    }
};