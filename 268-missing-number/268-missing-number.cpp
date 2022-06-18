class Solution {
public:
    
  
    
    int missingNumber(vector<int>& nums) {
        
      //cyclic sort 
        int i=0, n=nums.size();
    while  (i<n)
    {
        int crct = nums[i];
        if(nums[i] <n and nums[i] != nums[crct])
        {
            swap(nums[i], nums[crct]);
        }
        else
        {
            i++;
        }
    }
       for(i=0;i<n;i++)
        {
            if(i!=nums[i])
                return i;
        }
        return n;
    }
};
      
