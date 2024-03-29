class Solution {
public:/*
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        
        map<int, int> mp;
        for(int i = 0; i < n; i ++) {
            mp[nums[i]] ++;             // storing the frequency
        }
        
        int ans = 0;
        int pre = 0;
        for (auto i = mp.end(); i != mp.begin(); i--) {
            ans += i -> second + pre;   // total operations
                     // maintaing the previous frequency count
        }
        return ans;
    }
}; 
   int reductionOperations(vector<int>& nums)
   {
       sort(nums.begin(), nums.end());
       int n = nums.size();
       int count=0;
       for(int i = 0;i<n-1;i++)
       {
           if(nums[i]!=nums[i+1])
              count += n-i-1;
       }
       return count;
   }
}; 
    */
    
     int reductionOperations(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=dp[i-1]+1;
            }
        }
        int sum=0;
        for(auto x:dp){
            sum+=x;
        }
        return sum;
    }
};