class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
     
      // at every step we have 2 choices: to consider the string or not 
        //3D DP 
        int sz = strs.size();
       
        
        int dp[sz+1][m+1][n+1]; // max length of size of m zeroes and n ones 
        
 
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
                    //choice 2 
                        dp[i][j][k] = max(dp[i][j][k] , 1+ dp[i-1][j-z][k-o] );
                    
                   
                }
            }

        }
        return dp[sz][m][n];
    }
};
        
// This is a typical 0-1 knapsack problem ... only difference here is that we have to consider 2 wieghts.number of zeroes and number of ones . So what we do is simply traverse through the vector of string and see number of ones and number of zeroes in that string. Now we simply have 2 choices .. either to accept that string or not. In we follow both cases and see which result gives us max result.