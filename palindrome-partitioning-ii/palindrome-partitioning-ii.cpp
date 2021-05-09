  
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
        for(int g = 0;g<s.size();g++)
        {
            for(int i = 0,j = g;j<dp.size();i++,j++)
            {
                if(g==0)
                {
                    dp[i][j] = true;
                }
                else if(g==1)
                {
                    if(s[i] == s[j])
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }
        vector<int> strg(s.size());
        strg[0] = 0;
        for(int j = 1;j<strg.size();j++)
        {
            if(dp[0][j])  // puri string hi palindrome h to bool dp mai check kia aur storage mai 0 daldo
            {
                strg[j] = 0; //e.g string aba hoti to direct ans hi zero tha loop chalane ki zarurat nhi 
            }
            else
            { 
            int minv = INT_MAX;
            for(int i = j;i>=1;i--)
            {
                if(dp[i][j])
                {
                    if(strg[i-1]<minv)
                        minv = strg[i-1];
                }
            }
            strg[j] = minv+1;
            }
        }
        return strg[strg.size()-1];
    }
};