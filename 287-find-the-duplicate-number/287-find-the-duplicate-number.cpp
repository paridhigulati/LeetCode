class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
      //O(n) and O(1) --> cycle 
       int dup = -1;
        for(int i=0;i<nums.size();i++)
        {
            int curr = abs(nums[i]);
            if(nums[curr] < 0)
            {
                dup = curr;
                break;
            }
            nums[curr] *= -1;
        }
        
        for(auto i : nums)
        {
            i = abs(i);
        }
        return dup;
    }
};
    
    
    
    
    
    