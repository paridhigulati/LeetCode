class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <3) return nums.size();
        int idx=  2;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i] != nums[idx-2])
            {
                nums[idx]=nums[i];
                idx++;
            }
        }
        return idx;
    }
};