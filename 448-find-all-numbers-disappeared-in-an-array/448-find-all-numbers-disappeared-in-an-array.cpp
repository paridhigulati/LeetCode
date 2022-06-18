class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     
        vector<int>ans;
        int i=0, n = nums.size();
        
        while(i<n)
        {
            int crct = nums[i]-1;
            if(nums[i] != nums[crct])
                swap(nums[i], nums[crct]);
            else 
                i++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i+1 != nums[i] )
        ans.push_back(i+1);
        }
        return ans;
    }
};