class Solution {
public:
    int countVowelStrings(int n) {
     
        vector<int>dp(5,1);
        //dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j =1;j<5;j++)
            {
                dp[j] += dp[j-1];
            }
        }
        
     return dp[4];       
    }
};
