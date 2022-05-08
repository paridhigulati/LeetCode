class Solution {
public:
    string largestGoodInteger(string nums) {
     
        string ans = "";
        int n = nums.size();
        
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==nums[i+1] and nums[i+1] == nums[i+2])
            {
                ans = max(ans, {nums[i], nums[i+1], nums[i+2]});
            }
        }
       return ans;
        
        
    }
};