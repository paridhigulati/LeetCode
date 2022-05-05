class Solution {
public:
    int minPairSum(vector<int>& nums) {
     
        sort(nums.begin(), nums.end());
        int i=0,j=nums.size()-1;
        int sum = INT_MIN;
        
        while(i <= j )
        {
            
            sum = max(sum, nums[i++] + nums[j--]);
         }
        return sum;
            
           
            
        }
            
    
};