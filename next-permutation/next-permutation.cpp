class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        
        int i = n-1, j = n-1;
        
        // Find the largest index i such that nums[i] < nums[i + 1]:
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        
        // If no such index exists - reverse the array and were done:
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Find the largest index j > i such that nums[i] < nums[j]:
        i--;
        while (j > i && nums[j] <= nums[i]) j--;
        
        // Swap nums[i] and nums[j]:
        swap(nums[i], nums[j]);
        
        // Reverse the array from index i until the end:
        reverse(nums.begin() + i + 1, nums.end());
    }
};