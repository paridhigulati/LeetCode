class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     
//       brute  sort(nums.begin(), nums.end());
        
//         for(int i=0;i<nums.size()-1;i++)
//         {
//            if( nums[i] == nums[i+1]) 
//                return nums[i];
//         }
//         return -1;
        
        
        // RETURN START OF LL 
        
        int slow = nums[0], fast = nums[0];
        
       while(true)
       {
            slow = nums[slow];
            fast=nums[nums[fast]];
           if(slow == fast) break;
        }
        
   fast = nums[0];
        
        while(fast!=slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    
    
        
        
        
    }
};