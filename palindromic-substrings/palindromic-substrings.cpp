class Solution {
public:
    //GAP METHOD
    int countSubstrings(string s) {
        int n =s.size();
        bool dp[n+1][n+1];
        int count=0;
        for(int g=0;g<n;g++)
        {
            //jo bhi diagonal h vo 0 row se shuru aur column uska row+gap 
          for( int i=0,j=g;j<n ;i++,j++)
          {
              if(g==0)
                  dp[i][j]=true; // ek hi length ki string to hmesha palindrome
             else if(g==1)
              {
                  if(s[i]==s[j])
                    dp[i][j]=true;
                 else
                     dp[i][j]=false;
              }
             else 
             {
                if (s[i]==s[j] && dp[i+1][j-1]==true)
              {
                  dp[i][j]=true;
              }
             
              else
                   dp[i][j]=false;
              
             }
            if(dp[i][j])
                count++;
          }
              //sare diagonal 1st row se shuru aur last column mai khtm
        }
        return count;
    }
};