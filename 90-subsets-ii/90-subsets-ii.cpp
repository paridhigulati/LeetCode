class Solution {
public:
       vector<vector<int>>ans;
    
    void solve(int idx, vector<int> nums, vector<int> curr)
        
    {
        if(idx==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        //if not pick then dont pick any of that element
         if(curr.empty()||curr.back()!=nums[idx])
        {
            solve(idx+1, nums, curr);
        }
        
        //pick 
        curr.push_back(nums[idx]);
        solve(idx+1, nums, curr);
        
     
      
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      
     
        vector<int>curr;
        sort(nums.begin(), nums.end());
        solve(0, nums, curr);
        
        return ans;
    }
};
