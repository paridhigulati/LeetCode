class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        
        int maxi=0;
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            maxi = max(maxi, nums[i]);
            
            
            if(maxi >  nums[i+2])
                return false;
            
        }
            return true;
        }
};

