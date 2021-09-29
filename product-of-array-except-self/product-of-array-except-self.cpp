class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        // approach 1 : using 2 arrays leftProd and rightProd
        int n = nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=n-1;i>=1;i--)
        {
            right[i-1] = right[i]*nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            nums[i] = right[i]*left[i];
        }
        return nums;
    }
};

      