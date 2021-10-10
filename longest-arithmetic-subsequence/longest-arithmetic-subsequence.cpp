class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
     
        /* 2 dp states : difference and last value of AP with that difference 
        dp[val][diff] = number of elements of AP whose last element is val and difference is diff 
        9 4 7 2 10 --> series ending with 7 and diff = 3 
        ( 7,10  4,7 )*/
        int n = nums.size();
        if(n<=2) return n;
        vector<unordered_map<int,int>>dp(n);
        int maxLen = 2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff = nums[j]-nums[i];
                if(dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1; // found that diff once again 
                }
                else{
                    dp[j][diff] = 2; // atleast 2 values with certain diff
                }
                maxLen = max(maxLen, dp[j][diff]);
            }
        }
        return maxLen;
    
    }
};