class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g = 0;g<n;g++)
        {
            for(int i = 0,j = g;j<n;i++,j++)
            {
                if(g==0 || g==1)
                {
                    dp[i][j] = 0;
                }
                else if(g == 2)
                {
                    dp[i][j] = values[i]*values[i+1]*values[j];
                }
                else
                {
                    int ans = INT_MAX;
                    for(int k = i+1;k<j;k++)
                    {
                        int trai = values[i]*values[j]*values[k];
                        int pleft = dp[i][k];
                        int pright = dp[k][j];
                        int total = trai+pleft+pright;
                        if(total<ans)
                            ans = total;
                    }
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][n-1];
    }
};