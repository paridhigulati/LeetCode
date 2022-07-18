class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
        int prod = nums[0], maxi = nums[0], mini = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
          
             // here we would keep the negative product cuz neg and neg will result to positive product
            if(nums[i] <0)
            swap(maxi, mini);
            
              
            maxi = max(maxi* nums[i], nums[i]);
            mini = min(mini*nums[i], nums[i]);
            
            prod = max(maxi, prod);
        }
        return prod;
    }
};

 
    