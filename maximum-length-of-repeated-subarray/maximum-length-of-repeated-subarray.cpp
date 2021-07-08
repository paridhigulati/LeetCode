/*Since a common subarray of A and B must start at some A[i] and B[j], let dp[i][j] be the longest common prefix of A[i:] and B[j:]. Whenever A[i] == B[j], we know dp[i][j] = dp[i+1][j+1] + 1. Also, the answer is max(dp[i][j]) over all i, j.

We can perform bottom-up dynamic programming to find the answer based on this recurrence. Our loop invariant is that the answer is already calculated correctly and stored in dp for any larger i, j.*/

         /*   int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
  
          vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //INITIALISING 2D VECTOR 
       
      int ans=0;
      for(int i=1;i<dp.size();i++)
      {
          for(int j=1;j<dp[0].size();j++)
          {
              if(nums1[i-1]==nums2[j-1])
              {
                  dp[i][j]=dp[i-1][j-1]+1;
              }
                ans = max(ans,dp[i][j]);
          }
        
      }
        // your code here
        return ans;
    }
    
};


Approach #1: Brute Force with Initial Character Map [Time Limit Exceeded]
Intuition and Algorithm

In a typical brute force, for all starting indices i of A and j of B, we will check for the longest matching subarray A[i:i+k] == B[j:j+k] of length k. This would look roughly like the following psuedocode:

ans = 0
for i in [0 .. A.length - 1]:
    for j in [0 .. B.length - 1]:
        k = 0
        while (A[i+k] == B[j+k]): k += 1 #and i+k < A.length etc.
        ans = max(ans, k) */ 
        
        
        
        
        
   //     USING LCS 

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       // int n = nums1.size();
        //int m = nums2.size();
       /* int dp[n+1][m+1];
        int ans=0;
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<m+1;i++)
        {      dp[0][i]=0; }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
               ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
    
};
   
       
        
       
             
       int dp[m + 1][n + 1];
		int ans = 0;

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 0;
				} else if (nums1[i - 1] == nums2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					ans = max(ans, dp[i][j]);
				} else {
					dp[i][j] = 0;
                }
            }
        }
                return ans;
        }
    };

  */
        int n = nums1.size();
        int m = nums2.size();
        int ans = INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j] = 0;
                }
                else if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};