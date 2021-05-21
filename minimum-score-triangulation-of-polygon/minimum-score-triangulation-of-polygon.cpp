
//GAP METHOD
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
/*
Intuition: Given a set of numbers find an optimal solution for a problem considering the current number and the best you can get from the left and right sides.
Top Down:

class Solution {
public:
    int dynamic(vector<int>& A, vector<vector<int>>& dp, int i, int j){
        if(abs(i-j)<=1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int k, ans=INT_MAX;
        for(k=i+1; k<j; k++){
            ans=min(ans, dynamic(A, dp, i, k)+A[i]*A[j]*A[k]+dynamic(A, dp, k, j));
        }
        dp[i][j]=ans;
        return ans;
    }
    
    int minScoreTriangulation(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dynamic(arr, dp, 0, n-1);
    }
};
Bottom-Up:

class Solution {
public:
    int minScoreTriangulation(vector<int>& arr) {
        int len, i, j, k, n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(i=0; i<n; i++){
            dp[i][1]=0;
        }
        for(len=2; len<n; len++){
            for(i=0; i<n-len; i++){
                j=len;
                for(k=i+1; k<i+j; k++){
                    dp[i][j]=min(dp[i][j], dp[i][k-i]+arr[i]*arr[k]*arr[i+j]+dp[k][i+j-k]);
                }
            }
        }
        return dp[0][n-1];
    }
}; */