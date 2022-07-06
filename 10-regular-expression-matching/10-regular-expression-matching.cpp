class Solution {
public:
    bool isMatch(string str, string pat) {
        
        int n = str.size();
        
        int m = pat.size();
        
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = true;
                }
                
                else if(i == 0)
                {
                    dp[i][j] = false;
                }
                
                else if(j == 0)
                {
                    if(pat[i - 1] == '*')
                    {
                        dp[i][j] = dp[i - 2][j];
                    }
                    
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                
                else
                {
                    if(pat[i - 1] == '*')
                    {
                        dp[i][j] = dp[i - 2][j];
                        
                        if(pat[i - 2] == '.' || pat[i - 2] == str[j - 1])
                        {
                            dp[i][j] = dp[i][j] || dp[i][j - 1];
                        }
                    }
                    
                    else if(pat[i - 1] == '.')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    
                    else if(pat[i - 1] == str[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};