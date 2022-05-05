class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
     
        sort(nums.begin(), nums.end());
        
        int currSum =0, res=0, minDiff  =INT_MAX;
        
        int n =  nums.size();
        
        for(int i=0;i<n;i++)
        {
            int left = i+1, right = n-1;
            while(left < right)
            {
                currSum = nums[i]+nums[left]+nums[right];
                
                if(abs(target - currSum ) < minDiff)
                {
                   minDiff = abs(target-currSum);
                    res = currSum;
                }
                if(currSum== target ) return res; 
                
                else if(currSum > target ) right --;
                else 
                    left++;
            }
        }
        return res;
        
        
        
    }
};

   
           
             