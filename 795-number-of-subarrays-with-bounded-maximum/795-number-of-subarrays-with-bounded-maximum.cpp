class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       
        int cnt=0, i=0, j=0,window=0;
        int n = nums.size();
        
        while(j < n)
        {
            if(nums[j] >= left and nums[j] <= right)
            {
                window = j-i+1;
              
            }
            else if(nums[j] > right)
            {
             window = 0;
                i = j+1;
            }
            else if( nums[j] < left)
            {
                window = window;
            }
            cnt += window;
            j++;
            
        }
        return cnt;
        
    }
};