class Solution {
public:
    int minSubarray(vector<int>& nums)
    {
        int minSum = INT_MAX;
        int currSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            currSum += nums[i];
            minSum = min(minSum, currSum);
            if(currSum > 0)
            {
                currSum=0;
            }
            
        }
        return minSum;
    }
    int maxsumsubarray(vector<int>& nums)
    {
        int curr = 0;
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            curr += nums[i];
            maxSum = max(maxSum, curr);
            if(curr < 0) {curr = 0;
                         }
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
     
        int x = 1;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++) //entire array is negative
        {
            if(nums[i]>=0)
            {
                x=0;
                break;
            }
            ans = max(ans, nums[i]);
        }
        if(x) return ans;
        //case 1  -> max sum subarray (no wrap around)
            int ans1 = maxsumsubarray(nums);
             cout<<ans1<<" ";
        //case 2 -> wraparound
        int arrSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            arrSum += nums[i];
        }
        int ans2 = arrSum - minSubarray(nums);
        cout<<ans1<<" ";
        return max(ans1,ans2);
    }
};