class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     
        
        int sz  = nums.size();
        vector<int>n(sz,'*');
        
        for(int i=0;i<sz;i++)
        {
            if(nums[i] > 0 and nums[i]<=sz)
            n[nums[i]-1] = 1;
        }
        for(int i=0;i<n.size();i++)
        {
            if(n[i]=='*')
            {
              return i+1;
               // break;
            }
        }
        return nums.size()+1;
    }
};