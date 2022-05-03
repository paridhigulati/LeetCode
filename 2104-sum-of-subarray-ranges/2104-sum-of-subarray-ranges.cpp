class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long sum =0, n = nums.size();
        int mini , maxi;
        
        for(int i=0;i<n;i++)
        {
            mini = nums[i];
            maxi = nums[i];
            
            for(int j=i;j<n;j++)
            {
                mini =  min(mini, nums[j]);
                maxi =  max(maxi, nums[j]);
                sum += (maxi-mini);
            }
        }
        return sum;
    }
};