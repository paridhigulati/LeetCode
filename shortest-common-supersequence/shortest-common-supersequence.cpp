class Solution {
public:
    string s1,s2;
    int dp[1005][1005];
    int lcs(int i,int j)
    {
        int ans=0;
        if(i==s1.length() or j==s2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
            ans=1+lcs(i+1,j+1);
        else
            ans=max(lcs(i+1,j), lcs(i,j+1));
        return dp[i][j]=ans;
    }
    string shortestCommonSupersequence(string str1, string str2) 
    {
        s1=str1;
        s2=str2;
        memset(dp,-1,sizeof(dp));
        lcs(0,0);
        int i=0,j=0;
        string res;
        while(i<str1.length() && j<str2.length())
        {
            if(str1[i]==str2[j])
            {
                res+=str1[i];
                i++;
                j++;
            }
            else if(dp[i+1][j]<dp[i][j+1])
            {
                res+=str2[j];
                j++;
            }
            else 
            {
                res+=str1[i];
                i++;
            }
        }
        while(i<str1.length())
        {
            res+=str1[i];
            i++;
        }
        while(j<str2.length())
        {
            res+=str2[j];
            j++;
        }
        return res;
    }
};