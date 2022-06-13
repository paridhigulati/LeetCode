class Solution {
public:
   // vector<int> productExceptSelf(vector<int>& nums) {
        //ques to be asked -> does it contain zeroes 
        // brute using division better using 2 array left and right 
        //optimal 
        
//         int  n = nums.size();
//          vector<int>ans(n,1);
        
       
//         for(int i=1;i<n;i++)
//         {
//             ans[i] = ans[i-1] * nums[i-1];
            
//         }
//         int curr = nums[n-1];
//         for(int i=n-2;i>=0;i--)
//         {
//            ans[i] *= curr;
//             curr *= nums[i];
//         }
//         return ans;
//     }
   
// };
          vector<int> productExceptSelf(vector<int>& nums) {
              int n=nums.size();
        vector<int> pref(n,1), suf(n,1), ans(n,1);
              
              
              for(int i=1;i<n;i++)
              {
                  pref[i] = pref[i-1] * nums[i-1];
              }
              for(int i=n-2; i>=0;i--)
              {
                  suf[i] = suf[i+1]* nums[i+1];
              }

           for(int i = 0; i < n; i++)
            ans[i] = pref[i] * suf[i];
              
              return ans;
    }
};