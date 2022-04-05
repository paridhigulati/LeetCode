class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0)
                nums[i] = 1;
            else if(nums[i] < 0)
                nums[i] = -1;
            else if(nums[i] == 0)
                return 0;
        }
           for(int i=0;i<nums.size();i++)
        {
            prod *= nums[i];
        }
        
        
         if(prod > 0)
            return 1;
        return -1;
    }
};