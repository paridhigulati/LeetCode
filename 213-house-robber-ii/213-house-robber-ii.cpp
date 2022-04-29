class Solution {
public:
    

  int solve(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>dp(n+1);
       
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
    

    int rob(vector<int>& nums) {
      
        vector<int>temp1, temp2;
        
        int n = nums.size();
        
        if(n ==1) return nums[0];
         if(n==2) return max(nums[0],nums[1]);
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
          temp1.push_back(nums[i]);
            
            if(i!= n-1)
            temp2.push_back(nums[i]);
        }
        return max(solve(temp1) , solve(temp2));
    }
};