class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        int maxSum = nums[0];
        int curr = maxSum;
        for(int i=1;i<nums.size();i++)
        {
            curr = max(curr+nums[i],nums[i]);
            maxSum = max(curr,maxSum);
        }
        return maxSum;
    }
};
