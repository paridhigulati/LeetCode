class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int ans=0;
       
        for(int i=nums.size()-1; i>1;i--)
        {
         int j=0,k = i-1;
            while(j<k)
            {
            if(nums[j] + nums[k] > nums[i])
            { ans += (k-j);
                 k--;}
            else
            {
                j++;
            }
            }
        }
        return ans;
    }
};