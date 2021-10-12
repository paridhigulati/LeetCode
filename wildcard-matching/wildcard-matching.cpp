class Solution {
public:
  /*  bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        bool dp[m+1][n+1];
        for(int i = dp.size()-1;i>=0;i--)
        {
            for(int j = dp[0].size()-1;j>=0;j--)
            {
                if(i== dp.size()-1 and j==dp[0].size()-1) // last row and col exist
                {
                    //  last col ka last cell true (space space)
                    dp[i][j]=true;
                }
                else if(i==dp.size()-1)
                {
                    //last row hmesha false 
                    dp[i][j] = false;
                }
                else if(j==dp[0].size()-1)
                {
                    if(p[i]=='*')
                        dp[i][j] = dp[i+1][j];
                    else
                        dp[i][j]=false;
                }
                else{
                    // ? hai to diagonal
                    if(p[i]=='?'){
                        dp[i][j] = dp[i+1][j+1];} // chack diagonal
                    else if(p[i]=='*')
                    {
                     dp[i][j] = dp[i+1][j] || dp[i][j+1];   
                    }
                    else if(p[i]==s[i])
                    {
                     dp[i][j] = dp[i+1][j+1] ;
                    }
                    else {
                        dp[i][j] = false;
                    }
                    
                }
            }
        }
        return dp[0][0];
    }
};*/
        bool isMatch(string str, string pattern) {
        int m=pattern.size();
        int n=str.size();

        bool dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                dp[i][j]=false;
            }
        }
        dp[0][0]=true;            //if both string and pattern are empty

        for(int i=1;i<=m;i++){
           if(pattern[i-1]=='*')  //if pattern starts with '*' 
           dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?') //if the character matches or it a ? so we can replace it with any character, then answer depends on dp[i-1][j-1]
                dp[i][j]=dp[i-1][j-1];
                else if(pattern[j-1]=='*') //if it is a * then either we can skip 1 character of str or pattern
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
        }
};