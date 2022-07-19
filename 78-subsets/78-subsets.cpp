class Solution {
public:
    
    
    void getSubset(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(i==nums.size())
        {
            ans.push_back(curr);
                return;
        }
    //     //pick
        curr.push_back(nums[i]);
        getSubset(i+1, nums,curr,ans);
        
        //not pick
        curr.pop_back();
        getSubset(i+1,nums, curr, ans);
    }
    

    vector<vector<int>> subsets(vector<int>& nums) {
      
        
        // each element has 2 choices 
        vector<int>curr;
        vector<vector<int>>ans;
        
        getSubset( 0,nums,curr, ans);
        
        return ans;
    }
};



    
    



    
