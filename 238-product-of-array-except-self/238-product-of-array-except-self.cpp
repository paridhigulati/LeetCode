class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //ques to be asked -> does it contain zeroes 
        // brute using division better using 2 array left and right 
        //optimal 
        
        int  n = nums.size();
         vector<int>ans(n,1);
        
        
        for(int i=1;i<n;i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
            
        }
        
       int curr = nums[n-1];
        for(int i= n-2; i>=0;i--)
        {
            ans[i] *= curr;
            curr *= nums[i];
        }
        return ans;
    }
   
};