class Solution {
public:
    
   
    int rob(vector<int>& nums) {

        
            int n = nums.size();
        // prev is equivalent to, dp[i-1]
        int prev = nums[0]; // why so? if imagine i have a array of length 1 only so i will pick the 0th index
        
        // prev 2 is equivalent to dp[i-2]
        int prev2 = 0;
        
        // 0th index already done, solving for 1 to n-1 index
        for(int i=1;i<n;i++) {
            int take = nums[i] + prev2;
            int notTake = prev;
            int cur = max(take, notTake);
            prev2 = prev;
            prev = cur;
        }
        
        return prev;
    }
};