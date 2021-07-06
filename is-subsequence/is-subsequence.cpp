class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int dp[s.length()+1][t.length()+1],i,j;
        for(i=0;i<=s.length();i++)
        {
            dp[i][0]=0;
        }
        for(i=0;i<=t.length();i++)
        {
            dp[0][i]=0;
        }
        for(i=1;i<=s.length();i++)
        {
            for(j=1;j<=t.length();j++)
            {
                dp[i][j]=(s[i-1]==t[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[s.length()][t.length()]==s.length();
    }
};