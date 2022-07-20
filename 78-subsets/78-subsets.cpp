class Solution {
public:
    vector<vector<int>>ans;
    
    void getSubset(vector<int>nums, int idx, vector<int>curr)
    {
        int n= nums.size();
        if(idx==n)
        {
            ans.push_back(curr);
            return;
        }
        
        
            
            curr.push_back(nums[idx]);
            getSubset(nums, idx+1, curr);
            
            curr.pop_back();
            getSubset(nums, idx+1, curr);
            
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        
        getSubset(nums, 0, curr);
        return ans;
    }
};