class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
       
        for(int i=0;i<nums.size();i++)
        {
            nums[i] *= nums[i];
        }
         sort(nums.begin(), nums.end());
        return nums;
            
    }
}; 