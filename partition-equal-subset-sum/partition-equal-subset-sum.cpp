class Solution {
public:
    /*

bool canPartition(vector<int>& nums) {
    int n=(int)nums.size();
    int s=0;
    for(auto k: nums)
        s+=k;
    
    if(s&1)
        return false;
    
    s/=2;
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
           
    for(int i=0;i<=n;i++)
        for(int j=0;j<=s;j++)
        {
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(nums[i-1]<=j)
                dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s];
}
}; */
     bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum%2 !=0) 
        {return false;}
        
        sum=sum/2;
        
        int subset[n+1][sum+1];
        for(int i=0;i<=n;i++){
            subset[i][0]=true;
        }
        for(int j=1;j<=sum;j++){
            subset[0][j]=false;
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j< nums[i-1])
                    subset[i][j] = subset[i-1][j];
           else
                subset[i][j] = subset[i][j] or subset[i - 1][j - nums[i-1]];
            }
            }
          
             for(int i=1;i<=n;i++)
                 
                 for(int j=1;j<=sum;j++)
                 {
                if(j< nums[i-1])
                    
                    subset[i][j] = subset[i-1][j];
            if (j >= nums[i - 1])
                subset[i][j] = subset[i-1][j] or subset[i - 1][j - nums[i-1]];
     
                
        }
        return subset[n][sum];

    }
};



