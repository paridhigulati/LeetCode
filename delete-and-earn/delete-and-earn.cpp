class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        
        vector<int> dp(10001,0);
        int res=0;  // as no negative numbers are present
        // if present, do a map instead
        for(auto a:nums){
            dp[a]++; //stroing count of each number 
        }
        for(int i = 2; i < 10001; i++){
            dp[i]=max(dp[i-1], (i*dp[i])+dp[i-2]);
            res=max(res,dp[i]);
        }
        return res;
    }
};