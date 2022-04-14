class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
        // variable size sliding window
        int i=0,j=0;
         int n = nums.size();
        int sum=0, mini = 0, window=INT_MAX;
        
        
        while(j < n)
        {
         
            sum += nums[j];
            
            while(sum >= target )
                
            {  
                
               window = min (window, (j-i)+1) ;
                sum -= nums[i++];
                //i++;
             }
            j++; 
        }
        
        return window==INT_MAX ? 0 : window;
         
    }
};