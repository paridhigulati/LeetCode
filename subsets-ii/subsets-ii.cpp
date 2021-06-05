class Solution {
    /*
private:
    void sum(int index, vector<int>& nums,vector<int>& subset ,vector<vector<int>>ans )
    {
        ans.push_back(subset);
        
        for(int i=index;i<nums.size();i++)
        {
        if(i!=index && nums[i]==nums[i-1])
        
            continue;
        
         subset.push_back(nums[i]);
        sum(i+1, nums,subset, ans);
          subset.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int>subset;
      vector<vector<int>>ans;
     
        sort(nums.begin(),nums.end());
        sum(0,nums,subset,ans);
        return ans;
    }
};*/
    
    

public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;

    void backtrack(vector<int> &nums, int i, bool is_chosen){
        if(i >= n){
            ans.push_back(path);
            return;
        }
        // Not choosing nums[i]
        backtrack(nums, i+1, false);
        // Choosing nums[i]
        // NOTE: we only accept TTTTT...FFF
        // Ex. [3, 3, 3]: we only accept FFF, TFF, TTF, TTT
        // not accepting things like FTF or FFT because it will generate duplicates
        if(i >= 1 and nums[i-1] == nums[i] and !is_chosen) return;
        path.push_back(nums[i]);
        backtrack(nums, i+1, true);
        path.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        // Sort them so that duplicates will be consecutive
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, true);
        return ans;
    }
};