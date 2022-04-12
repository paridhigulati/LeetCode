class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
      int mini = INT_MAX, maxi = INT_MIN;
        int n = nums.size();
        
        for(int i = 1; i < n; i++){
            //Decreasing Value
            if(nums[i] < nums[i-1]) {
                mini = min(mini,nums[i]);
            }
        }
        
        for(int i = n-2; i >= 0; i--) {
            //Increasing value
            if(nums[i] > nums[i+1]){
                maxi = max(maxi,nums[i]);
            }
        }
        if(mini == INT_MAX && maxi == INT_MIN) // already sorted 
            return 0;
        
        int start = 0, end = n-1;
        
        for(; start < n; start++) {
            if(nums[start] > mini) break;
        }
        
        for(; end >= 0; end--) {
            if(nums[end] < maxi) break;
        }
        
        return end-start+1;
    }
};