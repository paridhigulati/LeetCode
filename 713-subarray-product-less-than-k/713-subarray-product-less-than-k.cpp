class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     
        
        int start=0, end=0, count=0, n=nums.size();
        long long p=1;
        
       
       while(end < n)
       {
            p *= nums[end];
           
        while(start <= end and p >= k )
        {
            
            p /= nums[start];
            start++;
        }
        if(p<k)
        {
            
            count += (end-start + 1);
        }
        end++;
       }
        return count;
    }
};
