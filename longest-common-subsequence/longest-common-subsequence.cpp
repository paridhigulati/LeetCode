class Solution {
public:
    /* RECURSIVE 
          int lcs(string s1, string s2, int n,int m)  
        {
        if(n==0||m==0)
            return 0;
        if(s1[n-1]==s2[m-1])
            return 1+ lcs(s1, s2, n-1,m-1);
        else
            return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
  int longestCommonSubsequence(string text1, string text2) 
  {
           int n = text1.size();
        int m = text2.size();
      return lcs(text1,text2,n,m);
    }
     
}; 
    
    //MEMOIZATION
    
    int dp[1001][1001];
    
    
    int lcs(string s1,string s2,int m,int n)
    {
        if(m==0||n==0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(s1[m-1]==s2[n-1])
            return dp[m][n] = 1+lcs(s1,s2,m-1,n-1);
        else
           return dp[m][n] = max(lcs(s1,s2,m-1,n), lcs(s1,s2,m,n-1));
    }

      
    
    
    int longestCommonSubsequence(string text1, string text2) 
  {
        
         int m = text1.size();
        int n = text2.size();
          memset(dp,-1,sizeof(dp));
      return lcs(text1,text2,m,n);
    }
};


        
     
  */

    int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m= text2.size(); 
        vector<vector<int>> lookup(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                    lookup[i][j] = 1 + lookup[i-1][j-1];
                else
                    lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
            }
        }
        return lookup[n][m];
    }
};