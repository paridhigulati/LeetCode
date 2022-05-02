class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        
            //inplace 
            int i=0, j =0;
            
            while(i<nums.size())
            {
                if(nums[i]%2 )
                {
                    i++; 
                }
                else if(nums[i] % 2 == 0)
                {
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }
            }
            return nums;
        }
};