class Solution {
public:
    
    void solve(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans)
    {
        if(i==nums.size())
        {
            ans.push_back(curr);
            return;
        }
    
    //choice 1----> take it
    curr.push_back(nums[i]);
        solve(i+1, nums,curr,ans);
    //choice 2-------->leave it
    curr.pop_back();
    solve(i+1,nums,curr,ans);
    
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        solve(0,nums,curr,ans);
        return ans;
        
    }
};

/*
 vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> n;
        gen(n,nums,0);
        return ans;
    }
    void gen(vector<int> n,vector<int> arr, int i){
        if(i==arr.size()){
            ans.push_back(n);
            return;
        }
        gen(n,arr,i+1);
        n.push_back(arr[i]);
        gen(n,arr,i+1);
    }
};
*/