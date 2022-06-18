class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
     // OPTIMAL : cyclic sort 
        
        int i=0, n= nums.size();
        while(i< n)
        {
            int crct = nums[i]-1;
            if(nums[i] != nums[crct])
            swap(nums[i], nums[crct]);
            else
                i++;
        }
        vector<int>res;
        
        for(int i = 0; i < n; i++){
            if(i!=nums[i]-1) //if current element is not placed in its right position that means that element is duplicate
                res.push_back(nums[i]);
        }
        
        return res;
        
        
        
    }
};