class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
     
      // at every step we have 2 choices: to consider the string or not 
        //3D DP 
        int sz = strs.size();
       
        
        int dp[sz+1][m+1][n+1]; // max length of size of m zeroes and n ones 
        
        // for(int i=0;i<=sz;i++)   // initialization 
        // {
        //     for(int j=0;j<=m;j++)
        //     {
        //         for(int k=0;k<=n;k++)
        //         {
        //             dp[i][j][k] = 0;
        //         }
        //     }
        // }
       memset(dp,0,sizeof dp);
        int ans=0;
        //fill up the table 
        for(int i=1;i<=sz;i++)
        {
            
            // int o = count(strs[i-1].begin(), strs[i-1].end(), '1');
            // int z = strs[i-1].size() - o;
            int z=0, o=0;
            for(int itr=0;itr<strs[i-1].size();itr++)
            {
                if(strs[i-1][itr] == '1') o++;
                else z++;
            }
            
            
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    // choice 1 -> not choosing the curr string 
                    dp[i][j][k] = dp[i-1][j][k];
                    
                    if(j>=z and k>= o)
                    
                        dp[i][j][k] = max(dp[i][j][k] , 1+ dp[i-1][j-z][k-o] );
                    
                    ans = max(ans, dp[i][j][k]);
                }
            }

        }
        return ans;
    }
};
        
       
//        for(int j=0;j<=m;j++)
//             {
//                 for(int k=0;k<=n;k++)
//                 {
//                     // current string not choosen
//                     dp[i][j][k] = dp[i-1][j][k];
 
//                     // check if current string can be choosen or not
//                     if(j-zeroes>=0 and k-ones>=0)
//                         dp[i][j][k] = max(dp[i][j][k],1+dp[i-1][j-zeroes][k-ones]);
 
//                     ans = max(ans,dp[i][j][k]);
 
