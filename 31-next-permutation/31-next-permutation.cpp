class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       
        int index = nums.size()-2;
        while(index >=0 and nums[index] >= nums[index +1])
        {
            index--;
        }
        if(index ==-1) // descending order
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=nums.size()-1;i >index;i--)
        {
            if(nums[i] >nums[index])
            {
                swap(nums[index], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
        
        
        
        
        
        
        
        
    }
};