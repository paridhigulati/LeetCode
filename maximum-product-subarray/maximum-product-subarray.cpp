class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int minSoFar = nums[0];
        int maxSoFar = nums[0];
        int finalMax = nums[0];
            for(int i=1;i<nums.size();i++)
        {
                int temp = maxSoFar;
                maxSoFar = max(nums[i]*maxSoFar,max( nums[i]*minSoFar, nums[i]));
                minSoFar = min(nums[i]*temp, min(nums[i]*minSoFar, nums[i]));
                if(maxSoFar > finalMax)
                    finalMax= maxSoFar;
          
           }
        return finalMax;
    }
};

      
// brute -> trying out every single subarray 
