class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        // if found someone smaller on right, swap point  aur left par smaller 
        
       int mini = INT_MAX, maxi = INT_MIN;
        
        int n = nums.size();
        
           for(int i=0;i<n-1;i++)
           {
            if(nums[i] > nums[i+1] )
            {
                mini = min(mini, nums[i+1]);
          
            }
            
           }

        for(int j=n-1; j>0;j --)
        
        {
            if( nums[j] < nums[j-1])
                maxi = max(maxi, nums[j-1]);
        }
        
        int l=0,r=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > mini)
            {
                l=i;
                break;
            }
                
        }
        for(int j=n-1;j>0;j--)
        {
            if(nums[j] < maxi)
            {
                r=j;
                break;
            }
        }
        return r-l>0 ? r-l+1 : 0;
    }
};